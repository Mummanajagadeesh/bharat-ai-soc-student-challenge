import os
import numpy as np

# === CONFIGURATION ===
input_folder = "model_weights_fixed8"   # Q1.7 fixed-point int16
output_folder = "model_weights_2"       # reconstructed floats
SCALE = 128.0  # Q1.7 scaling factor (2^7)

os.makedirs(output_folder, exist_ok=True)

# Walk through the input folder
for root, dirs, files in os.walk(input_folder):
    # Create matching subdirectories in the output folder
    rel_path = os.path.relpath(root, input_folder)
    out_dir = os.path.join(output_folder, rel_path)
    os.makedirs(out_dir, exist_ok=True)

    for file in files:
        if file.endswith(".txt"):
            in_path = os.path.join(root, file)
            out_path = os.path.join(out_dir, file)

            # Load fixed-point integers
            data_int = np.loadtxt(in_path, dtype=np.int16)

            # Convert to floating-point Q1.7
            data_float = data_int.astype(np.float32) / SCALE

            # Save as text, preserving shape
            np.savetxt(out_path, data_float, fmt="%.8f")

            print(f"Converted {in_path} -> {out_path}")

print("✅ Conversion back to floats complete.")
