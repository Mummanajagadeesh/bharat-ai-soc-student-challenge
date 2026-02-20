import numpy as np

def parse_shape(shape_str):
    # Supports both "(3, 3, 64)" and "3 3 64" formats
    shape_str = shape_str.strip().replace("(", "").replace(")", "")
    parts = shape_str.replace(",", " ").split()
    return [int(p) for p in parts]

def count_elements_in_file(file_path):
    with open(file_path, "r") as f:
        data = f.read().split()
        return len(data)

# Read shapes.txt and verify each file
errors = []
with open("shapes.txt", "r") as f:
    for line in f:
        if ":" not in line:
            continue
        file_path, shape_str = line.strip().split(":", 1)
        file_path = file_path.strip()
        shape_str = shape_str.strip()

        try:
            expected_shape = parse_shape(shape_str)
            expected_count = np.prod(expected_shape)
            actual_count = count_elements_in_file(file_path)

            if expected_count != actual_count:
                errors.append(
                    f"{file_path}: Expected {expected_count} elements from shape {shape_str}, "
                    f"but found {actual_count}"
                )
        except Exception as e:
            errors.append(f"{file_path}: Error processing line — {e}")

# Output results
if not errors:
    print("✅ All shapes in shapes.txt match the actual data.")
else:
    print("❌ Mismatched dimensions found:")
    for error in errors:
        print(" -", error)
