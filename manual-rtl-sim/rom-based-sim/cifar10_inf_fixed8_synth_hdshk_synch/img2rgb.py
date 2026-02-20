import os
from PIL import Image
import numpy as np

# Ensure the output directory exists
output_dir = "image_txt"
os.makedirs(output_dir, exist_ok=True)

# Load and ensure image is 32x32 RGB
image = Image.open("image.png").convert("RGB")
image = image.resize((32, 32))  # Resize if needed

# Convert to numpy array
np_image = np.array(image)

# Extract RGB channels
red_channel = np_image[:, :, 0]
green_channel = np_image[:, :, 1]
blue_channel = np_image[:, :, 2]

# Function to save a channel to text file with fixed spacing
def save_channel_to_txt(channel, filename):
    with open(filename, 'w') as f:
        for row in channel:
            formatted_row = ' '.join(f"{val:3d}" for val in row)
            f.write(formatted_row + '\n')

# Save each channel with aligned spacing
save_channel_to_txt(red_channel, os.path.join(output_dir, "image_r.txt"))
save_channel_to_txt(green_channel, os.path.join(output_dir, "image_g.txt"))
save_channel_to_txt(blue_channel, os.path.join(output_dir, "image_b.txt"))

print("Formatted RGB channels saved.")
