import numpy as np
from PIL import Image
import os
import scipy.special  # for softmax

# === CIFAR-10 Label Mapping ===
label_map = {
    0: "airplane", 1: "automobile", 2: "bird", 3: "cat", 4: "deer",
    5: "dog", 6: "frog", 7: "horse", 8: "ship", 9: "truck"
}

# === Fixed-point conversion (Q1.7) ===
FRAC_BITS = 7
SCALE = 1 << FRAC_BITS  # 128

def float_to_fixed_q17(arr):
    return (arr * SCALE).astype(np.int64)

def fixed_to_float_q17(arr):
    return arr.astype(np.float64) / SCALE

# === Load and preprocess image ===
def load_image(img_path, img_size=(32, 32)):
    img = Image.open(img_path).convert("RGB").resize(img_size)
    img_array = np.asarray(img, dtype=np.float64) / 255.0
    return np.expand_dims(img_array, axis=0), np.asarray(img.resize(img_size))

# === Load weights ===
def load_weights(layer_name):
    kernel_file = f"model_weights_fixed8/{layer_name}_kernel.txt"
    bias_file = f"model_weights_fixed8/{layer_name}_bias.txt"
    kernel = np.loadtxt(kernel_file, dtype=np.int16)
    bias = np.loadtxt(bias_file, dtype=np.int16)
    kernel = kernel.astype(np.float64) / SCALE
    bias = bias.astype(np.float64) / SCALE
    return kernel, bias

def reshape_weights(kernel_raw, bias_raw, shape):
    return kernel_raw.reshape(shape), bias_raw

# === Layers ===
def relu(x):
    return np.maximum(0, x)

def pad_input(x, pad):
    return np.pad(x, ((0, 0), (pad, pad), (pad, pad), (0, 0)), mode='constant')

def conv2d(x, kernel, bias, stride=1, padding='same'):
    batch, in_h, in_w, in_c = x.shape
    k_h, k_w, _, out_c = kernel.shape
    pad = (k_h - 1) // 2 if padding == 'same' else 0
    if pad > 0:
        x = pad_input(x, pad)
    out_h = (in_h + 2 * pad - k_h) // stride + 1
    out_w = (in_w + 2 * pad - k_w) // stride + 1
    out = np.zeros((batch, out_h, out_w, out_c), dtype=np.float64)
    for b in range(batch):
        for h in range(out_h):
            for w in range(out_w):
                for c in range(out_c):
                    h_start = h * stride
                    w_start = w * stride
                    region = x[b, h_start:h_start + k_h, w_start:w_start + k_w, :]
                    out[b, h, w, c] = np.sum(region * kernel[:, :, :, c]) + bias[c]
    return out

def max_pool(x, size=2, stride=2):
    batch, in_h, in_w, in_c = x.shape
    out_h = (in_h - size) // stride + 1
    out_w = (in_w - size) // stride + 1
    out = np.zeros((batch, out_h, out_w, in_c), dtype=np.float64)
    for b in range(batch):
        for h in range(out_h):
            for w in range(out_w):
                for c in range(in_c):
                    h_start = h * stride
                    w_start = w * stride
                    region = x[b, h_start:h_start+size, w_start:w_start+size, c]
                    out[b, h, w, c] = np.max(region)
    return out

def global_avg_pool(x):
    return np.mean(x, axis=(1, 2))

def dense(x, kernel, bias):
    return np.dot(x, kernel) + bias

# === Load all model weights ===
weights_shapes = {
    "00_conv2d":       (3, 3, 3, 16),
    "01_conv2d_1":     (3, 3, 16, 16),
    "03_conv2d_2":     (3, 3, 16, 32),
    "04_conv2d_3":     (3, 3, 32, 32),
    "06_conv2d_4":     (3, 3, 32, 64),
    "07_conv2d_5":     (3, 3, 64, 64),
    "10_dense":        (64, 10),
}

weights = {}
for layer_name, shape in weights_shapes.items():
    k_raw, b_raw = load_weights(layer_name)
    k, b = reshape_weights(k_raw, b_raw, shape)
    weights[layer_name] = (k, b)

# === Inference with dumping/reloading fixed-point ===
def run_and_capture(x, weights):
    def capture(name, x_stage):
        fixed_vals = float_to_fixed_q17(x_stage)
        return fixed_to_float_q17(fixed_vals)

    x = conv2d(x, *weights['00_conv2d'], padding='same'); x = capture("conv2d_0", x)
    x = relu(x); x = capture("relu_0", x)

    x = conv2d(x, *weights['01_conv2d_1'], padding='same'); x = capture("conv2d_1", x)
    x = relu(x); x = capture("relu_1", x)
    x = max_pool(x); x = capture("max_pool_1", x)

    x = conv2d(x, *weights['03_conv2d_2'], padding='same'); x = capture("conv2d_2", x)
    x = relu(x); x = capture("relu_2", x)
    x = conv2d(x, *weights['04_conv2d_3'], padding='same'); x = capture("conv2d_3", x)
    x = relu(x); x = capture("relu_3", x)
    x = max_pool(x); x = capture("max_pool_2", x)

    x = conv2d(x, *weights['06_conv2d_4'], padding='same'); x = capture("conv2d_4", x)
    x = relu(x); x = capture("relu_4", x)
    x = conv2d(x, *weights['07_conv2d_5'], padding='same'); x = capture("conv2d_5", x)
    x = relu(x); x = capture("relu_5", x)
    x = max_pool(x); x = capture("max_pool_3", x)

    x = global_avg_pool(x); x = capture("global_avg_pool", x)

    logits = dense(x.reshape(1, -1), *weights['10_dense']); logits = capture("dense_logits", logits)

    probs = scipy.special.softmax(logits, axis=-1); probs = capture("softmax", probs)
    return probs[0], int(np.argmax(probs))

# === Main loop over 100 images ===
if __name__ == "__main__":
    correct_count = 0
    total_count = 0

    for class_idx, class_name in label_map.items():
        folder_path = os.path.join("sample_images", class_name)
        for img_file in sorted(os.listdir(folder_path)):
            if not img_file.endswith(".png"):
                continue
            img_path = os.path.join(folder_path, img_file)
            img_input, _ = load_image(img_path)
            probs, pred_class = run_and_capture(img_input, weights)

            actual_label = class_name
            predicted_label = label_map[pred_class]
            print(f"{img_file} | Actual: {actual_label:<10} | Predicted: {predicted_label}")

            if actual_label == predicted_label:
                correct_count += 1
            total_count += 1

    print(f"\nCorrect: {correct_count}/{total_count} ({correct_count/total_count*100:.2f}%)")
