import numpy as np
import os
from PIL import Image

# === CIFAR-10 Label Mapping ===
label_map = {
    0: "airplane", 1: "automobile", 2: "bird", 3: "cat", 4: "deer",
    5: "dog", 6: "frog", 7: "horse", 8: "ship", 9: "truck"
}
label_map_rev = {v: k for k, v in label_map.items()}

# === Load 100 images (10 per class) from sample_images ===
def load_100_images(base_path, img_size=(32, 32)):
    images = []
    labels = []

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

    return np.array(images), np.array(labels)

# Path to sample_images folder
sample_images_path = r"sample_images"
x_test, y_test = load_100_images(sample_images_path)

# === Model and Inference Functions (unchanged from your code) ===
def load_weights(layer_name):
    kernel_file = f"model_weights/{layer_name}_kernel.txt"
    bias_file = f"model_weights/{layer_name}_bias.txt"
    kernel = np.loadtxt(kernel_file, dtype=np.float32)
    bias = np.loadtxt(bias_file, dtype=np.float32)
    return kernel, bias

def relu(x):
    return np.maximum(0, x)

def pad_input(x, pad):
    return np.pad(x, ((0, 0), (pad, pad), (pad, pad), (0, 0)), mode='constant')

def conv2d(x, kernel, bias, stride=1, padding='same'):
    batch, in_h, in_w, in_c = x.shape
    k_h, k_w, _, out_c = kernel.shape
    if padding == 'same':
        pad = (k_h - 1) // 2
        x = pad_input(x, pad)
    out_h = (in_h + 2 * pad - k_h) // stride + 1
    out_w = (in_w + 2 * pad - k_w) // stride + 1
    out = np.zeros((batch, out_h, out_w, out_c), dtype=np.float32)
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
    out = np.zeros((batch, out_h, out_w, in_c), dtype=np.float32)
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

def reshape_weights(kernel_raw, bias_raw, shape):
    kernel = kernel_raw.reshape(shape)
    return kernel, bias_raw

def run_inference(x, weights):
    x = conv2d(x, *weights['00_conv2d'], padding='same')
    x = relu(x)
    x = conv2d(x, *weights['01_conv2d_1'], padding='same')
    x = relu(x)
    x = max_pool(x)

    x = conv2d(x, *weights['03_conv2d_2'], padding='same')
    x = relu(x)
    x = conv2d(x, *weights['04_conv2d_3'], padding='same')
    x = relu(x)
    x = max_pool(x)

    x = conv2d(x, *weights['06_conv2d_4'], padding='same')
    x = relu(x)
    x = conv2d(x, *weights['07_conv2d_5'], padding='same')
    x = relu(x)
    x = max_pool(x)

    x = global_avg_pool(x)
    x = dense(x, *weights['10_dense'])
    return x

# === Load weights ===
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

# === Run inference on all 100 images ===
correct = 0

for idx in range(len(x_test)):
    img = np.expand_dims(x_test[idx], axis=0)
    logits = run_inference(img, weights)
    pred = np.argmax(logits)
    true = int(y_test[idx])
    print(f"Image {idx:03}: Predicted = {pred} ({label_map[pred]}), Actual = {true} ({label_map[true]}) {'✅' if pred == true else '❌'}")
    if pred == true:
        correct += 1

print(f"\n🎯 Total Accuracy: {correct}/100 ({correct}%)")
