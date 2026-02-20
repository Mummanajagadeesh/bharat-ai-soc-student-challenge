import numpy as np
import os
import time
from PIL import Image

# === CIFAR-10 Label Mapping ===
label_map = {
    0: "airplane", 1: "automobile", 2: "bird", 3: "cat", 4: "deer",
    5: "dog", 6: "frog", 7: "horse", 8: "ship", 9: "truck"
}
label_map_rev = {v: k for k, v in label_map.items()}

# === Fixed-point parameters (Q1.7) ===
FRAC_BITS = 7
SCALE = 1 << FRAC_BITS   # 128

# === Load 100 images (10 per class) ===
def load_100_images(base_path, img_size=(32, 32)):
    images, labels, filenames = [], [], []
    for class_name in sorted(label_map_rev.keys()):
        class_dir = os.path.join(base_path, class_name)
        for i in range(10):
            filename = f"{class_name}_{i}.png"
            file_path = os.path.join(class_dir, filename)
            if not os.path.exists(file_path):
                raise FileNotFoundError(f"Image not found: {file_path}")
            img = Image.open(file_path).convert("RGB").resize(img_size)
            img_array = np.asarray(img, dtype=np.float32) / 255.0
            images.append(img_array)
            labels.append(label_map_rev[class_name])
            filenames.append(f"{class_name}/{filename}")
    return np.array(images), np.array(labels), filenames

# === Load Fixed-Point Weights ===
def load_kernel_file_fixed(filename, shape):
    k_h, k_w, in_c, out_c = shape
    kernel = np.zeros(shape, dtype=np.float32)
    with open(filename, "r") as f:
        lines = [line.strip() for line in f if line.strip()]
    expected_lines = k_h * k_w * in_c
    if len(lines) != expected_lines:
        raise ValueError(f"Expected {expected_lines} lines in {filename}, got {len(lines)}")
    line_idx = 0
    for i in range(k_h):
        for j in range(k_w):
            for c in range(in_c):
                values = [int(v) / SCALE for v in lines[line_idx].split()]
                if len(values) != out_c:
                    raise ValueError(f"Line {line_idx+1} in {filename} has {len(values)} values, expected {out_c}")
                kernel[i, j, c, :] = values
                line_idx += 1
    return kernel

def load_weights_fixed(layer_name, shape):
    kernel_file = f"model_weights_fixed8/{layer_name}_kernel.txt"
    bias_file = f"model_weights_fixed8/{layer_name}_bias.txt"
    if len(shape) == 4:
        kernel = load_kernel_file_fixed(kernel_file, shape)
    elif len(shape) == 2:
        kernel = np.loadtxt(kernel_file, dtype=np.int32).reshape(shape) / SCALE
    else:
        raise ValueError(f"Unsupported shape for layer {layer_name}: {shape}")
    if os.path.exists(bias_file):
        bias = np.loadtxt(bias_file, dtype=np.int32) / SCALE
    else:
        bias = np.zeros(shape[-1], dtype=np.float32)
    return kernel, bias

# === Math Functions ===
def relu(x): return np.maximum(0, x)
def pad_input(x, pad): return np.pad(x, ((0,0),(pad,pad),(pad,pad),(0,0)), mode='constant')

def conv2d(x, kernel, bias, stride=1, padding='same'):
    batch, in_h, in_w, in_c = x.shape
    k_h, k_w, _, out_c = kernel.shape
    pad = (k_h - 1)//2 if padding=='same' else 0
    x = pad_input(x, pad)
    out_h = (in_h + 2*pad - k_h)//stride + 1
    out_w = (in_w + 2*pad - k_w)//stride + 1
    out = np.zeros((batch, out_h, out_w, out_c), dtype=np.float32)
    for b in range(batch):
        for h in range(out_h):
            for w in range(out_w):
                region = x[b, h*stride:h*stride+k_h, w*stride:w*stride+k_w, :]
                for c in range(out_c):
                    out[b,h,w,c] = np.sum(region * kernel[:,:,:,c]) + bias[c]
    return out

def max_pool(x, size=2, stride=2):
    batch, in_h, in_w, in_c = x.shape
    out_h = (in_h - size)//stride + 1
    out_w = (in_w - size)//stride + 1
    out = np.zeros((batch, out_h, out_w, in_c), dtype=np.float32)
    for b in range(batch):
        for h in range(out_h):
            for w in range(out_w):
                region = x[b, h*stride:h*stride+size, w*stride:w*stride+size, :]
                out[b,h,w,:] = np.max(region, axis=(0,1))
    return out

def global_avg_pool(x): return np.mean(x, axis=(1,2))
def dense(x, kernel, bias): return np.dot(x, kernel) + bias

# === Run Inference ===
def run_inference(x, weights):
    # Block1
    x1 = relu(conv2d(x, *weights['01_conv2d']))
    x1 = relu(conv2d(x1, *weights['02_conv2d_1']))
    shortcut1 = conv2d(x, *weights['03_conv2d_2'])
    x = x1 + shortcut1
    x = max_pool(x)

    # Block2
    x2 = relu(conv2d(x, *weights['06_conv2d_3']))
    x2 = relu(conv2d(x2, *weights['07_conv2d_4']))
    shortcut2 = conv2d(x, *weights['08_conv2d_5'])
    x = x2 + shortcut2
    x = max_pool(x)

    # Head
    x = global_avg_pool(x)
    x = dense(x, *weights['12_dense'])
    return x

# === Expected Weight Shapes ===
weights_shapes = {
    "01_conv2d":    (3,3,3,28),
    "02_conv2d_1":  (3,3,28,28),
    "03_conv2d_2":  (1,1,3,28),    # Block1 shortcut
    "06_conv2d_3":  (3,3,28,56),
    "07_conv2d_4":  (3,3,56,56),
    "08_conv2d_5":  (1,1,28,56),   # Block2 shortcut
    "12_dense":     (56,10),
}

# === Load weights from fixed-point files ===
print("Loading weights...")
weights = {}
for layer_name, shape in weights_shapes.items():
    kernel, bias = load_weights_fixed(layer_name, shape)
    weights[layer_name] = (kernel, bias)
print("Weights loaded successfully!\n")

# === Load test images ===
sample_images_path = r"sample_images"
x_test, y_test, filenames = load_100_images(sample_images_path)

# === Run inference on all 100 images and measure time ===
timing_results = []
correct = 0

print("Running inference on 100 images...\n")
for idx in range(len(x_test)):
    img = np.expand_dims(x_test[idx], axis=0)
    
    # Measure inference time
    start_time = time.perf_counter()
    logits = run_inference(img, weights)
    end_time = time.perf_counter()
    
    inference_time = (end_time - start_time) * 1000  # Convert to milliseconds
    
    pred = np.argmax(logits)
    true = int(y_test[idx])
    is_correct = pred == true
    
    timing_results.append({
        'image': filenames[idx],
        'time_ms': inference_time,
        'prediction': label_map[pred],
        'actual': label_map[true],
        'correct': is_correct
    })
    
    if is_correct:
        correct += 1
    
    print(f"Image {idx+1:03}/100: {filenames[idx]:30} | Time: {inference_time:7.3f} ms | Pred: {label_map[pred]:10} | Actual: {label_map[true]:10} | {'✓' if is_correct else '✗'}")

# === Calculate statistics ===
times = [r['time_ms'] for r in timing_results]
min_time = min(times)
max_time = max(times)
avg_time = np.mean(times)
std_dev = np.std(times)
accuracy = (correct / len(x_test)) * 100

# === Save results to text file ===
output_file = "inference_benchmark_results.txt"
with open(output_file, 'w') as f:
    f.write("=" * 80 + "\n")
    f.write("CIFAR-10 INFERENCE BENCHMARK RESULTS\n")
    f.write("=" * 80 + "\n\n")
    
    f.write("Individual Image Results:\n")
    f.write("-" * 80 + "\n")
    f.write(f"{'Image':<35} {'Time (ms)':<12} {'Prediction':<12} {'Actual':<12} {'Result'}\n")
    f.write("-" * 80 + "\n")
    
    for r in timing_results:
        f.write(f"{r['image']:<35} {r['time_ms']:>10.3f}   {r['prediction']:<12} {r['actual']:<12} {'CORRECT' if r['correct'] else 'WRONG'}\n")
    
    f.write("\n" + "=" * 80 + "\n")
    f.write("SUMMARY STATISTICS\n")
    f.write("=" * 80 + "\n\n")
    f.write(f"Total Images:           100\n")
    f.write(f"Minimum Time:           {min_time:.3f} ms\n")
    f.write(f"Maximum Time:           {max_time:.3f} ms\n")
    f.write(f"Average Time:           {avg_time:.3f} ms\n")
    f.write(f"Standard Deviation:     {std_dev:.3f} ms\n")
    f.write(f"Accuracy:               {correct}/100 ({accuracy:.2f}%)\n")
    f.write("\n" + "=" * 80 + "\n")

print("\n" + "=" * 80)
print("SUMMARY STATISTICS")
print("=" * 80)
print(f"Total Images:           100")
print(f"Minimum Time:           {min_time:.3f} ms")
print(f"Maximum Time:           {max_time:.3f} ms")
print(f"Average Time:           {avg_time:.3f} ms")
print(f"Standard Deviation:     {std_dev:.3f} ms")
print(f"Accuracy:               {correct}/100 ({accuracy:.2f}%)")
print("=" * 80)
print(f"\nResults saved to: {output_file}")
