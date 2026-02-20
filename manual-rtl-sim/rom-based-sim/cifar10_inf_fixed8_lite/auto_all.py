import shutil
import subprocess
import os
from tabulate import tabulate

# === CIFAR-10 Label Mapping ===
label_map = {
    0: "airplane", 1: "automobile", 2: "bird", 3: "cat", 4: "deer",
    5: "dog", 6: "frog", 7: "horse", 8: "ship", 9: "truck"
}
class_names = list(label_map.values())

# === Paths ===
base_path = "sample_images"
dst_path = "image.png"

results = []
correct_count = 0
image_counter = 0

for class_name in class_names:  # Go through each class folder
    class_dir = os.path.join(base_path, class_name)
    for i in range(10):  # 10 images per class
        file_name = f"{class_name}_{i}.png"
        src_path = os.path.join(class_dir, file_name)

        if not os.path.exists(src_path):
            print(f"❌ Missing image: {src_path}")
            continue

        # === Step 1: Copy to image.png ===
        shutil.copy(src_path, dst_path)

        # === Step 2: Run python img2rgb.py ===
        subprocess.run(["python", "img2rgb.py"], check=True)

        # === Step 3: Compile with iverilog ===
        subprocess.run(["iverilog", "-o", "test", "cnn.v"], check=True)

        # === Step 4: Run vvp test and capture output ===
        result = subprocess.run(["vvp", "test"], capture_output=True, text=True)
        output = result.stdout.strip()

        # === Step 5: Search for predicted class name ===
        predicted_class = None
        for cname in class_names:
            if cname in output:
                predicted_class = cname
                break

        if not predicted_class:
            predicted_class = "UNKNOWN"

        # === Update accuracy count ===
        if predicted_class == class_name:
            correct_count += 1

        # === Collect results ===
        results.append([
            image_counter,
            file_name,
            class_name,
            predicted_class
        ])

        print(f"Processed {file_name}: Actual={class_name}, Pred={predicted_class}")

        image_counter += 1

        # === Generate live table with summary ===
        accuracy = (correct_count / image_counter) * 100
        summary = [["", "", "Total Accuracy", f"{correct_count}/{image_counter} ({accuracy:.2f}%)"]]

        table = tabulate(results, headers=["Image#", "File Name", "Actual", "Predicted"], tablefmt="grid")
        table_with_summary = table + "\n" + tabulate(summary, tablefmt="grid")

        # === Print live table to terminal ===
        os.system('cls' if os.name == 'nt' else 'clear')
        print(table_with_summary)

        # === Save to results.txt dynamically ===
        with open("results.txt", "w") as f:
            f.write(table_with_summary)

print("\n✅ All results saved to results.txt")
