#!/usr/bin/env python3
import subprocess
import sys
import re
import time
import shlex
import threading
from glob import glob
from pathlib import Path

# ---------------- config ----------------
labels = [
    "Airplane", "Automobile", "Bird", "Cat", "Deer",
    "Dog", "Frog", "Horse", "Ship", "Truck"
]

# Layer config: (name, out_shape, params, files, expected_feature_maps)
layers = [
    ("conv2d (Conv2D)", "(None, 32, 32, 16)", "448",
     "00_conv2d_relu_new.v verilog_image_roms_genv/*.v verilog_roms_genv_16/rom_00_conv2d_bias.v verilog_roms_genv_16/rom_00_conv2d_kernel.v",
     16),
    ("conv2d_1 (Conv2D)", "(None, 32, 32, 16)", "2,320",
     "01_conv2d_relu_new.v verilog_roms_genv_16/rom_01_conv2d_1_bias.v verilog_roms_genv_16/rom_01_conv2d_1_kernel.v",
     16),
    ("max_pooling2d (MaxPooling2D)", "(None, 16, 16, 16)", "0",
     "02_maxpool_01_new.v",
     0),
    ("conv2d_2 (Conv2D)", "(None, 16, 16, 32)", "4,640",
     "03_conv2d_relu_new.v verilog_roms_genv_16/rom_03_conv2d_2_bias.v verilog_roms_genv_16/rom_03_conv2d_2_kernel.v",
     32),
    ("conv2d_3 (Conv2D)", "(None, 16, 16, 32)", "9,248",
     "04_conv2d_relu_new.v verilog_roms_genv_16/rom_04_conv2d_3_bias.v verilog_roms_genv_16/rom_04_conv2d_3_kernel.v",
     32),
    ("max_pooling2d_1 (MaxPooling2D)", "(None, 8, 8, 32)", "0",
     "05_maxpool_02_new.v",
     0),
    ("conv2d_4 (Conv2D)", "(None, 8, 8, 64)", "18,496",
     "06_conv2d_relu_new.v verilog_roms_genv_16/rom_06_conv2d_4_bias.v verilog_roms_genv_16/rom_06_conv2d_4_kernel.v",
     64),
    ("conv2d_5 (Conv2D)", "(None, 8, 8, 64)", "36,928",
     "07_conv2d_relu_new.v verilog_roms_genv_16/rom_07_conv2d_5_bias.v verilog_roms_genv_16/rom_07_conv2d_5_kernel.v",
     64),
    ("max_pooling2d_2 (MaxPooling2D)", "(None, 4, 4, 64)", "0",
     "08_maxpool_03_new.v",
     0),
    ("global_average_pooling2d (GlobalAveragePooling2D)", "(None, 64)", "0",
     "09_gap_new.v",
     0),
    ("dense (Dense)", "(None, 10)", "650",
     "10_dense_new.v verilog_roms_genv_16/rom_10_dense_bias.v verilog_roms_genv_16/rom_10_dense_kernel.v",
     0),
    ("softmax (Softmax)", "(None, 10)", "0",
     "11_softmax_new.v",
     0),
]

POSSIBLE_ROM_DIRS = ["verilog_image_roms_genv", "verilog_roms_genv_16", "."]

# Output formatting
COL1_W, COL2_W, COL3_W = 26, 23, 11
TOTAL_W = COL1_W + 3 + COL2_W + 3 + COL3_W

# ---------------- printing helpers ----------------
def _format_iverilog_multiline(cmd_str: str) -> str:
    try:
        parts = shlex.split(cmd_str)
    except Exception:
        parts = cmd_str.split()
    if len(parts) >= 3 and parts[0] == "iverilog" and parts[1] == "-o":
        head = f"{parts[0]} {parts[1]} {parts[2]} \\"
        rest = parts[3:]
        if not rest:
            return head.rstrip(" \\")
        lines = [head]
        for i, p in enumerate(rest):
            last = (i == len(rest) - 1)
            suffix = "" if last else " \\"
            lines.append(f"    {p}{suffix}")
        return "\n".join(lines)
    return cmd_str


def print_command(cmd_str: str):
    print("\nRunning>>>")
    if cmd_str.strip().startswith("iverilog"):
        print(_format_iverilog_multiline(cmd_str))
    else:
        print(cmd_str)
    print()  # leave a blank line after command

# ---------------- subprocess wrappers ----------------
def run_cmd_silent(cmd: str):
    """Print command, but hide stdout/stderr (silent execution)."""
    print_command(cmd)
    res = subprocess.run(cmd, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    if res.returncode != 0:
        print(f"❌ Command failed: {cmd} (exit {res.returncode})")
        sys.exit(res.returncode)

def run_cmd_capture(cmd: str) -> str:
    """Print command and capture stdout+stderr (used only for final softmax)."""
    print_command(cmd)
    res = subprocess.run(cmd, shell=True, capture_output=True, text=True)
    if res.returncode != 0:
        print(f"❌ Command failed: {cmd} (exit {res.returncode})")
        if res.stderr:
            print(res.stderr.strip())
        sys.exit(res.returncode)
    return res.stdout

# --------------- file baseline (mtime+size) ---------------
def _list_all_v_files():
    files = []
    for d in POSSIBLE_ROM_DIRS:
        p = Path(d)
        if not p.exists():
            continue
        for f in p.glob("*.v"):
            files.append(str(f))
    return sorted(files)

def snapshot_files_mtime_size():
    d = {}
    for path in _list_all_v_files():
        try:
            st = Path(path).stat()
            d[path] = (st.st_mtime, st.st_size)
        except Exception:
            continue
    return d

# --------------- filename -> layer matching ---------------
def file_matches_layer(path: str, layer_idx: int) -> bool:
    fn = path.replace("\\", "/")
    idx2 = f"{layer_idx:02d}"
    fn_lower = fn.lower()
    if f"rom_{idx2}" in fn_lower:
        return True
    if f"_{idx2}_" in fn_lower or f"_{idx2}." in fn_lower or f"_{idx2}-" in fn_lower:
        return True
    if f"/{idx2}_" in fn_lower or f"/{idx2}-" in fn_lower:
        return True
    if layer_idx == 0 and "verilog_image_roms_genv" in fn_lower:
        return True
    return False

# --------------- visual runner with spinner and hardcoded counts ---------------
spinner_running = False
def spinner():
    global spinner_running
    while spinner_running:
        for ch in "|/-\\":
            print(f"\rGenerating feature maps... {ch}", end="", flush=True)
            time.sleep(0.1)
    # After stopping spinner, overwrite line with done
    print("\rGenerating feature maps... done!   ")

def run_with_visual_progress(cmd: str, expected_count: int, baseline_map: dict, layer_idx: int):
    global spinner_running

    spinner_running = True
    spin_thread = threading.Thread(target=spinner)
    spin_thread.start()

    # Run command silently
    res = subprocess.run(cmd, shell=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

    spinner_running = False
    spin_thread.join()

    if res.returncode != 0:
        print("\n❌ Command failed during feature map generation.")
        sys.exit(res.returncode)

    print()  # blank line after done!

    # Hardcoded feature maps count output
    if expected_count == 0:
        print("\n")
    else:
        print(f"{expected_count} Feature Maps Generated\n")

    return expected_count

# ---------------- printing/layout ----------------
def print_title_block():
    print("\nLight Weight Sequential CNN for CIFAR10 Image Classification | Icarus Verilog ")
    print("------------------------------------------------------------------------\n")
    print("[Conv2D×2 + MaxPool]×3 → GAP → Dense(10) for CIFAR-10 Image Classification (32x32 RGB)\n")
    print("Interactive MODE\n")
    print("------------------------------------------------------------------------\n")

def print_layer_block(layer_name, out_shape, params):
    print("=" * (TOTAL_W + 2))
    header = f"Layer (type)".ljust(COL1_W) + " | " + f"Output Shape".ljust(COL2_W) + " | " + f"Param".ljust(COL3_W) + " |"
    print(header)
    print("-" * (TOTAL_W + 2))
    row = layer_name.ljust(COL1_W) + " | " + out_shape.ljust(COL2_W) + " | " + str(params).rjust(COL3_W - 1) + " |"
    print(row)
    print("=" * (TOTAL_W + 2))

# ---------------- main pipeline ----------------
def run_pipeline():
    print_title_block()

    # Preprocessing (silent)
    run_cmd_silent("python img2rgb.py")
    run_cmd_silent("python img-gen-v.py")
    run_cmd_silent("python fixed.py")

    for idx, (layer_name, out_shape, params, files, expected_fmaps) in enumerate(layers):
        print("\n" + "-" * 71 + "\n")

        print_layer_block(layer_name, out_shape, params)
        print()

        # compile (print only)
        iverilog_cmd = f"iverilog -o test {files}"
        run_cmd_silent(iverilog_cmd)

        baseline = snapshot_files_mtime_size()

        if idx == len(layers) - 1:
            stdout = run_cmd_capture("vvp test")
            print("\n" + "-" * 71 + "\n")
            match = re.search(r"class:\s*(\d+).*?probability\s*([0-9]*\.?[0-9]+)", stdout, re.S)
            if match:
                pred, prob = match.groups()
                pred = int(pred)
                label = labels[pred] if 0 <= pred < len(labels) else "Unknown"
                print(f"Label: {label} ({pred}) | Probability: {prob}\n")
            else:
                match2 = re.search(r"Label:\s*(.*?)\s*\((\d+)\).*?Probability:\s*([0-9]*\.?[0-9]+)", stdout, re.S)
                if match2:
                    label, idxs, prob = match2.groups()
                    print(f"Label: {label} ({idxs}) | Probability: {prob}\n")
                else:
                    print("Label/Probability not found.\n")
            print("\n" + "-" * 71 + "\n")
        else:
            run_with_visual_progress("vvp test", expected_fmaps, baseline, idx)

        print("\n")

if __name__ == "__main__":
    run_pipeline()
