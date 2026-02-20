import os
import numpy as np

# === PARAMETERS ===
input_dir = "model_weights"               # original float weights
fixed_dir = "model_weights_fixed8"        # Q1.7 fixed-point
recon_dir = "model_weights_2"             # reconstructed float weights from fixed-point

TOTAL_BITS = 8
FRAC_BITS = 7                             # Q1.7 format
SCALE = 1 << FRAC_BITS                    # 128
MAX_VAL = (1 << (TOTAL_BITS - 1)) - 1     # 127
MIN_VAL = -(1 << (TOTAL_BITS - 1))        # -128

os.makedirs(fixed_dir, exist_ok=True)
os.makedirs(recon_dir, exist_ok=True)

overflow_count = 0

def float_to_fixed_str(num_str):
    """Convert float string to fixed-point int string, preserving empty lines."""
    global overflow_count
    if not num_str.strip():
        return ""
    val = float(num_str)
    fixed_val = int(round(val * SCALE))
    if fixed_val > MAX_VAL:
        fixed_val = MAX_VAL
        overflow_count += 1
    elif fixed_val < MIN_VAL:
        fixed_val = MIN_VAL
        overflow_count += 1
    return str(fixed_val)

def fixed_to_float_str(num_str):
    """Convert fixed-point int string back to float string, preserving empty lines."""
    if not num_str.strip():
        return ""
    val = int(num_str)
    return f"{val / SCALE:.8f}"

# === STEP 1: Float → Q1.7 int8 ===
for filename in os.listdir(input_dir):
    if filename.lower().endswith(".txt"):
        in_path = os.path.join(input_dir, filename)
        fixed_path = os.path.join(fixed_dir, filename)

        with open(in_path, "r") as f:
            lines = f.readlines()

        fixed_lines = []
        for line in lines:
            parts = line.strip().split()
            if not parts:
                fixed_lines.append("\n")
                continue
            fixed_parts = [float_to_fixed_str(p) for p in parts]
            fixed_lines.append(" ".join(fixed_parts) + "\n")

        with open(fixed_path, "w") as f:
            f.writelines(fixed_lines)

print(f"[STEP 1] Fixed-point conversion complete. Overflow count: {overflow_count}")
print(f"Fixed-point files saved in: {fixed_dir}")

# === STEP 2: Q1.7 int8 → Float ===
for filename in os.listdir(fixed_dir):
    if filename.lower().endswith(".txt"):
        fixed_path = os.path.join(fixed_dir, filename)
        recon_path = os.path.join(recon_dir, filename)

        with open(fixed_path, "r") as f:
            lines = f.readlines()

        recon_lines = []
        for line in lines:
            parts = line.strip().split()
            if not parts:
                recon_lines.append("\n")
                continue
            recon_parts = [fixed_to_float_str(p) for p in parts]
            recon_lines.append(" ".join(recon_parts) + "\n")

        with open(recon_path, "w") as f:
            f.writelines(recon_lines)

print(f"[STEP 2] Reconstruction complete. Files saved in: {recon_dir}")
