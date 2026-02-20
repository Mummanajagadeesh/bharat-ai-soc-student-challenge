import os
import numpy as np
from tensorflow.keras.models import load_model

# Load model
model = load_model("model.keras")

# Create output folder
output_dir = "model_weights"
os.makedirs(output_dir, exist_ok=True)

# Iterate through layers
for i, layer in enumerate(model.layers):
    weights = layer.get_weights()
    if not weights:
        continue  # skip layers without weights

    # Only save the first weight (kernel), skip biases
    kernel = weights[0]  # first element is typically the kernel

    filename = os.path.join(output_dir, f"{i:02d}_{layer.name}_kernel.txt")

    # Save kernel as space-separated values, preserving dimensions
    with open(filename, "w") as f:
        if kernel.ndim == 1:
            # 1D weight (e.g., embedding)
            f.write(" ".join(f"{val:.8f}" for val in kernel))
        elif kernel.ndim == 2:
            # Dense layer weights: (input_dim, output_dim)
            for row in kernel:
                f.write(" ".join(f"{val:.8f}" for val in row) + "\n")
        elif kernel.ndim == 3:
            # 1D Convolution: (kernel_size, input_channels, output_channels)
            for k in kernel:
                for ch in k:
                    f.write(" ".join(f"{val:.8f}" for val in ch) + "\n")
                f.write("\n")  # separate kernels
        elif kernel.ndim == 4:
            # 2D Convolution: (kernel_height, kernel_width, input_channels, output_channels)
            for i_h in kernel:
                for i_w in i_h:
                    for in_ch in i_w:
                        f.write(" ".join(f"{val:.8f}" for val in in_ch) + "\n")
                    f.write("\n")
                f.write("\n")
        else:
            f.write(f"# Unsupported kernel shape: {kernel.shape}\n")
