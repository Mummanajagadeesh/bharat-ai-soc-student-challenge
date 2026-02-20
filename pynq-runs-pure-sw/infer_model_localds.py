import os
import time
import numpy as np
from PIL import Image
import tensorflow as tf

# ================= CONFIG =================
MODEL_PATH = "model.keras"
IMAGE_ROOT = "sample_images"
OUTPUT_FILE = "results_model.txt"
IMG_SIZE = (32, 32)

LABELS = [
    "airplane", "automobile", "bird", "cat", "deer",
    "dog", "frog", "horse", "ship", "truck"
]
label_to_idx = {name: i for i, name in enumerate(LABELS)}

# ================= LOAD MODEL =================
model = tf.keras.models.load_model(MODEL_PATH)
print("✅ Model loaded")

# ================= LOAD IMAGES =================
image_paths = []
true_labels = []

for label in sorted(os.listdir(IMAGE_ROOT)):
    class_dir = os.path.join(IMAGE_ROOT, label)
    if not os.path.isdir(class_dir):
        continue
    for fname in sorted(os.listdir(class_dir)):
        if fname.endswith(".png"):
            image_paths.append(os.path.join(class_dir, fname))
            true_labels.append(label_to_idx[label])

assert len(image_paths) == 100, "Expected exactly 100 images"

# ================= INFERENCE =================
times = []
predictions = []
correct = 0

lines = []
header = f"{'Idx':>3} | {'Image':<20} | {'Pred':<10} | {'Actual':<10} | {'Time(ms)':>9} | OK"
lines.append(header)
lines.append("-" * len(header))

for idx, (img_path, true) in enumerate(zip(image_paths, true_labels)):
    img = Image.open(img_path).convert("RGB").resize(IMG_SIZE)
    x = np.asarray(img, dtype=np.float32) / 255.0
    x = np.expand_dims(x, axis=0)

    start = time.perf_counter()
    logits = model.predict(x, verbose=0)
    end = time.perf_counter()

    pred = int(np.argmax(logits))
    t_ms = (end - start) * 1000

    times.append(t_ms)
    predictions.append(pred)

    ok = pred == true
    if ok:
        correct += 1

    line = (
        f"{idx:03} | {os.path.basename(img_path):<20} | "
        f"{LABELS[pred]:<10} | {LABELS[true]:<10} | "
        f"{t_ms:9.3f} | {'✅' if ok else '❌'}"
    )

    print(line)
    lines.append(line)

# ================= STATS =================
times = np.array(times)
accuracy = correct / len(true_labels) * 100

stats = [
    "",
    "========== SUMMARY ==========",
    f"Total Images : {len(true_labels)}",
    f"Correct      : {correct}",
    f"Accuracy     : {accuracy:.2f} %",
    "",
    "Inference Time (ms):",
    f"Min   : {times.min():.3f}",
    f"Max   : {times.max():.3f}",
    f"Avg   : {times.mean():.3f}",
    f"Std   : {times.std():.3f}",
]

for s in stats:
    print(s)
    lines.append(s)

# ================= SAVE FILE =================
with open(OUTPUT_FILE, "w") as f:
    f.write("\n".join(lines))

print(f"\n📁 Results saved to {OUTPUT_FILE}")
