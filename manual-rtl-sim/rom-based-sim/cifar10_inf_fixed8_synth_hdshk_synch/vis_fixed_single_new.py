import numpy as np
from PIL import Image
import os
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
import scipy.special  # for softmax

# === CIFAR-10 Label Mapping ===
label_map = {
    0: "airplane", 1: "automobile", 2: "bird", 3: "cat", 4: "deer",
    5: "dog", 6: "frog", 7: "horse", 8: "ship", 9: "truck"
}

# === Utility: Normalize for visualization only ===
def normalize_feature_maps(x):
    x_min = x.min(axis=(0, 1), keepdims=True)
    x_max = x.max(axis=(0, 1), keepdims=True)
    return (x - x_min) / (x_max - x_min + 1e-8)

# === Fixed-point conversion (Q1.7) ===
FRAC_BITS = 7
SCALE = 1 << FRAC_BITS  # 128

def float_to_fixed_q17(arr):
    """Convert float64 to Q1.7 fixed-point integers."""
    return (arr * SCALE).astype(np.int64)  # int64 to avoid overflow

def fixed_to_float_q17(arr):
    """Convert Q1.7 fixed-point integers back to float64."""
    return arr.astype(np.float64) / SCALE

# === Load and preprocess image ===
def load_image(img_path, img_size=(32, 32)):
    if not os.path.exists(img_path):
        raise FileNotFoundError(f"Image not found: {img_path}")
    img = Image.open(img_path).convert("RGB").resize(img_size)
    img_array = np.asarray(img, dtype=np.float64) / 255.0
    return np.expand_dims(img_array, axis=0), np.asarray(img.resize(img_size))

# === Model Layers ===
def load_weights(layer_name):
    kernel_file = f"model_weights_fixed8/{layer_name}_kernel.txt"
    bias_file = f"model_weights_fixed8/{layer_name}_bias.txt"
    kernel = np.loadtxt(kernel_file, dtype=np.int16)
    bias = np.loadtxt(bias_file, dtype=np.int16)
    kernel = kernel.astype(np.float64) / SCALE
    bias = bias.astype(np.float64) / SCALE
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

def reshape_weights(kernel_raw, bias_raw, shape):
    kernel = kernel_raw.reshape(shape)
    return kernel, bias_raw

# === Load model weights ===
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

# === Visualizer Class ===
class FeatureMapViewer:
    def __init__(self, stages, class_probs, predicted_class, original_image):
        self.stages = stages
        self.index = 0
        self.class_probs = class_probs
        self.predicted_class = predicted_class
        self.original_image = original_image
        self.fig = plt.figure(figsize=(12, 8))
        self.cid = self.fig.canvas.mpl_connect('key_press_event', self.on_key)
        self.show_stage()

    def show_stage(self):
        self.fig.clf()
        title, data = self.stages[self.index]

        if title == "original_image":
            ax = self.fig.add_subplot(1, 1, 1)
            ax.imshow(self.original_image)
            ax.axis("off")
            ax.set_title("Original Image")

        elif title == "rgb_split":
            axs = [self.fig.add_subplot(1, 3, i + 1) for i in range(3)]
            channels = ['Red', 'Green', 'Blue']
            for i in range(3):
                rgb = np.zeros_like(self.original_image)
                rgb[:, :, i] = self.original_image[:, :, i]
                axs[i].imshow(rgb)
                axs[i].set_title(f"{channels[i]} Channel")
                axs[i].axis("off")
            self.fig.suptitle("RGB Channel Split (in Color)", fontsize=14)

        elif title == "softmax_summary":
            ax = self.fig.add_subplot(1, 1, 1)
            ax.imshow(self.original_image)
            ax.axis("off")
            pred = label_map[self.predicted_class]
            conf = self.class_probs[self.predicted_class]
            ax.set_title(f"Predicted: {pred} (Confidence: {conf:.2%})")

        elif title == "softmax":
            ax = self.fig.add_subplot(1, 1, 1)
            ax.bar(range(10), self.class_probs)
            ax.set_xticks(range(10))
            ax.set_xticklabels([label_map[i] for i in range(10)], rotation=45)
            ax.set_title(f"Softmax Output\nPredicted: {label_map[self.predicted_class]}")

        elif title == "dense_logits":
            values = data.flatten()
            ax = self.fig.add_subplot(1, 1, 1)
            ax.bar(range(len(values)), values)
            ax.set_xticks(range(len(values)))
            ax.set_xticklabels([label_map[i] for i in range(len(values))], rotation=45)
            ax.set_title("Dense Layer Logits")

        elif title == "global_avg_pool":
            values = data.flatten()
            ax = self.fig.add_subplot(1, 1, 1)
            ax.bar(range(len(values)), values)
            ax.set_title("Global Average Pool Output")
            ax.set_xlabel("Channel")
            ax.set_ylabel("Mean Value")

        elif data is not None and data.ndim == 4:
            feature_maps_display = normalize_feature_maps(data[0])
            num_channels = feature_maps_display.shape[-1]
            grid_cols = int(np.ceil(np.sqrt(num_channels)))
            grid_rows = int(np.ceil(num_channels / grid_cols))
            gs = gridspec.GridSpec(grid_rows, grid_cols, figure=self.fig)

            for i in range(num_channels):
                ax = self.fig.add_subplot(gs[i])
                ax.imshow(feature_maps_display[:, :, i], cmap='viridis')
                ax.axis('off')

        self.fig.suptitle(f"{self.index + 1}/{len(self.stages)}: {title}", fontsize=14)
        plt.tight_layout()
        self.fig.canvas.draw()

    def on_key(self, event):
        if event.key == 'right':
            self.index = (self.index + 1) % len(self.stages)
            self.show_stage()
        elif event.key == 'left':
            self.index = (self.index - 1) % len(self.stages)
            self.show_stage()

# === Inference with cumulative fixed-point simulation ===
def run_and_capture(x, weights, original_image):
    stages = []

    def capture(name, x_stage):
        stages.append((name, x_stage.copy() if x_stage is not None else None))
        if x_stage is not None:
            fixed_vals = float_to_fixed_q17(x_stage)
            os.makedirs(name, exist_ok=True)
            if x_stage.ndim == 4:
                for i in range(x_stage.shape[-1]):
                    np.savetxt(f"{name}/feature_map_{i}.txt", fixed_vals[0, :, :, i], fmt="%d")
            else:
                np.savetxt(f"{name}.txt", fixed_vals.flatten(), fmt="%d")
            return fixed_to_float_q17(fixed_vals)
        return x_stage

    capture("original_image", None)
    capture("rgb_split", None)

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

    predicted_class = int(np.argmax(probs))
    stages.append(("softmax_summary", None))

    return stages, probs[0], predicted_class

# === Run Script ===
if __name__ == "__main__":
    image_path = "image.png"
    image_input, original_image_np = load_image(image_path)
    stages, class_probs, predicted_class = run_and_capture(image_input, weights, original_image_np)
    viewer = FeatureMapViewer(stages, class_probs, predicted_class, original_image_np)
    plt.show()
