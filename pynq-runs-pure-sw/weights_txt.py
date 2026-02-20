import os
import numpy as np
from tensorflow.keras.models import load_model

# Load model
model = load_model("model.keras")

print(model.summary())  # Print model summary for verification

# Create output folder
output_dir = "model_weights"
os.makedirs(output_dir, exist_ok=True)

# Iterate through layers
for i, layer in enumerate(model.layers):
    weights = layer.get_weights()
    if not weights:
        continue  # skip layers without weights

    # Save kernel
    kernel = weights[0]
    kernel_filename = os.path.join(output_dir, f"{i:02d}_{layer.name}_kernel.txt")
    with open(kernel_filename, "w") as f:
        if kernel.ndim == 1:
            f.write("\n".join(f"{val:.8f}" for val in kernel))
        elif kernel.ndim == 2:
            for row in kernel:
                f.write(" ".join(f"{val:.8f}" for val in row) + "\n")
        elif kernel.ndim == 3:
            for k in kernel:
                for ch in k:
                    f.write(" ".join(f"{val:.8f}" for val in ch) + "\n")
                f.write("\n")
        elif kernel.ndim == 4:
            for i_h in kernel:
                for i_w in i_h:
                    for in_ch in i_w:
                        f.write(" ".join(f"{val:.8f}" for val in in_ch) + "\n")
                    f.write("\n")
                f.write("\n")
        else:
            f.write(f"# Unsupported kernel shape: {kernel.shape}\n")

    # Save bias if exists (one value per line)
    if len(weights) > 1:
        bias = weights[1]
        bias_filename = os.path.join(output_dir, f"{i:02d}_{layer.name}_bias.txt")
        with open(bias_filename, "w") as f:
            for val in bias:
                f.write(f"{val:.8f}\n")
