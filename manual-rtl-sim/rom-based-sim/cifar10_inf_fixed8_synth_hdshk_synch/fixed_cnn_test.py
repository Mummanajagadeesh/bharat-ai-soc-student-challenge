import subprocess
import sys
import shutil
import os
import signal
from tqdm import tqdm
import platform

IS_WINDOWS = platform.system() == "Windows"

def run_cmd(cmd, silent=False):
    try:
        if IS_WINDOWS:
            creationflags = subprocess.CREATE_NEW_PROCESS_GROUP
            preexec_fn = None
        else:
            creationflags = 0
            preexec_fn = os.setsid

        if silent:
            process = subprocess.Popen(
                cmd, shell=True,
                stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                creationflags=creationflags,
                preexec_fn=preexec_fn
            )
        else:
            print(f"\n>>> Running: {cmd}")
            process = subprocess.Popen(
                cmd, shell=True,
                stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                creationflags=creationflags,
                preexec_fn=preexec_fn
            )

        stdout, stderr = process.communicate()
        if process.returncode != 0:
            print(f"❌ Command failed: {cmd}")
            if silent:
                print(stdout.decode())
                print(stderr.decode())
            sys.exit(process.returncode)
        return subprocess.CompletedProcess(args=cmd, returncode=process.returncode, stdout=stdout, stderr=stderr)

    except KeyboardInterrupt:
        print("\n❌ Interrupted by user! Terminating subprocess...")
        try:
            if IS_WINDOWS:
                process.send_signal(signal.CTRL_BREAK_EVENT)
            else:
                os.killpg(os.getpgid(process.pid), signal.SIGINT)
        except Exception:
            pass
        sys.exit(130)

labels = ["airplane", "automobile", "bird", "cat", "deer", "dog", "frog", "horse", "ship", "truck"]

image_files = []
for label in labels:
    for i in range(10):
        image_files.append(f"sample_images/{label}/{label}_{i}.png")

output_file = "predictions.txt"

try:
    with open(output_file, "w") as f:
        f.write(f"{'actual':<15} | {'predicted':<15} | {'correct'}\n")
        f.write("-" * 45 + "\n")

        correct = 0

        for img_path in tqdm(image_files, desc="Processing images"):
            shutil.copy(img_path, "image.png")

            run_cmd("python img2rgb.py", silent=True)
            run_cmd("python img-gen-v.py", silent=True)
            run_cmd("python fixed.py", silent=True)

            steps = [
                ("00_conv2d_relu_new.v verilog_image_roms_genv/*.v verilog_roms_genv_16/rom_00_conv2d_bias.v verilog_roms_genv_16/rom_00_conv2d_kernel.v", True),
                ("01_conv2d_relu_new.v verilog_roms_genv_16/rom_01_conv2d_1_bias.v verilog_roms_genv_16/rom_01_conv2d_1_kernel.v", True),
                ("02_maxpool_01_new.v", True),
                ("03_conv2d_relu_new.v verilog_roms_genv_16/rom_03_conv2d_2_bias.v verilog_roms_genv_16/rom_03_conv2d_2_kernel.v", True),
                ("04_conv2d_relu_new.v verilog_roms_genv_16/rom_04_conv2d_3_bias.v verilog_roms_genv_16/rom_04_conv2d_3_kernel.v", True),
                ("05_maxpool_02_new.v", True),
                ("06_conv2d_relu_new.v verilog_roms_genv_16/rom_06_conv2d_4_bias.v verilog_roms_genv_16/rom_06_conv2d_4_kernel.v", True),
                ("07_conv2d_relu_new.v verilog_roms_genv_16/rom_07_conv2d_5_bias.v verilog_roms_genv_16/rom_07_conv2d_5_kernel.v", True),
                ("08_maxpool_03_new.v", True),
                ("09_gap_new.v", True),
                ("10_dense_new.v verilog_roms_genv_16/rom_10_dense_bias.v verilog_roms_genv_16/rom_10_dense_kernel.v", True),
                ("11_softmax_new.v", True),
            ]

            out = None
            for files, run_vvp in steps:
                run_cmd(f"iverilog -o test {files}", silent=True)
                if run_vvp:
                    out = run_cmd("vvp test", silent=True)

            output_text = out.stdout.decode() if out else ""
            pred_line = [line for line in output_text.splitlines() if "Predicted class:" in line]
            if pred_line:
                pred_text = pred_line[0].split(":")[1].strip()
                pred_idx_str = pred_text.split()[0]
                pred_idx = int(pred_idx_str)
                pred_label = labels[pred_idx]
            else:
                pred_idx = -1
                pred_label = "Unknown"

            true_idx = None
            true_label = None
            for i, label in enumerate(labels):
                if label in img_path:
                    true_idx = i
                    true_label = label
                    break

            is_correct = (true_idx == pred_idx)
            if is_correct:
                correct += 1

            actual_str = f"{true_label} ({true_idx})" if true_label is not None else "Unknown (-1)"
            predicted_str = f"{pred_label} ({pred_idx})" if pred_label != "Unknown" else "Unknown (-1)"

            line = f"{actual_str:<15} | {predicted_str:<15} | {str(is_correct)}\n"
            print(line, end="")
            f.write(line)
            f.flush()

        accuracy = correct / len(image_files) * 100
        summary = (
            f"\n✅ All images processed!\n"
            f"Accuracy: {accuracy:.2f}% ({correct}/{len(image_files)})\n"
        )
        print(summary)
        f.write(summary)

except KeyboardInterrupt:
    print("\n❌ Execution stopped by user (Ctrl+C). Exiting gracefully.")
    sys.exit(130)
