import shutil
import subprocess
import os

# === CIFAR-10 Label Mapping ===
label_map = {
    0: "airplane", 1: "automobile", 2: "bird", 3: "cat", 4: "deer",
    5: "dog", 6: "frog", 7: "horse", 8: "ship", 9: "truck"
}
class_names = list(label_map.values())

# === Paths ===
base_path = "sample_images"
class_name = "truck"
image_idx =  9 # 4th image (0-based index)
src_path = os.path.join(base_path, class_name, f"{class_name}_{image_idx}.png")
dst_path = "image.png"

# === Step 1: Copy selected image ===
if not os.path.exists(src_path):
    raise FileNotFoundError(f"Source image not found: {src_path}")

shutil.copy(src_path, dst_path)
print(f"✅ Copied {src_path} -> {dst_path}")

# === Step 2: Run python img2rgb.py ===
subprocess.run(["python", "img2rgb.py"], check=True)
print("✅ Ran img2rgb.py")

# === Step 3: Compile with iverilog ===
subprocess.run(["iverilog", "-o", "test", "cnn.v"], check=True)
print("✅ Compiled cnn.v with iverilog")

# === Step 4: Run vvp test and capture output ===
result = subprocess.run(["vvp", "test"], capture_output=True, text=True)
output = result.stdout.strip()

# Save full raw output (optional debug)
print("\n--- Raw vvp Output ---")
print(output)
print("----------------------\n")

# === Step 5: Search for predicted class name ===
predicted_class = None
for cname in class_names:
    if cname in output:
        predicted_class = cname
        break

if predicted_class:
    print(f"🎯 Predicted class: {predicted_class}")
else:
    print("❌ Could not find any class name in vvp output.")
