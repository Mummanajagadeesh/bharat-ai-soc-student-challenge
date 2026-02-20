import os
import glob
import re

# Get all *_shape.txt files
shape_files = glob.glob("*_shape.txt")

# Function to extract layer number and file type for sorting
def extract_layer_info(filename):
    match = re.search(r"layer_(\d+)_(\w+)_shape\.txt", filename)
    if match:
        layer_num = int(match.group(1))
        param_type = match.group(2)
        return (layer_num, param_type)
    else:
        return (float('inf'), filename)  # Sort unknown patterns last

# Sort files by layer number and parameter type
shape_files.sort(key=extract_layer_info)

# Write the output
with open("shapes.txt", "w") as out_file:
    for shape_file in shape_files:
        data_filename = shape_file.replace("_shape.txt", ".txt")
        with open(shape_file, "r") as f:
            shape_data = f.read().strip()
        out_file.write(f"{data_filename}: {shape_data}\n")

print("shapes.txt created with layer-wise sorted shape data.")
