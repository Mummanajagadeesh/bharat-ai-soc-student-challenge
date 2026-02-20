import os
import numpy as np
import matplotlib.pyplot as plt
from PIL import Image

weights_dir = "weights_txt"
image_path = "image.png"

class_labels = {
    0: "airplane", 1: "automobile", 2: "bird", 3: "cat", 4: "deer",
    5: "dog", 6: "frog", 7: "horse", 8: "ship", 9: "truck"
}

def relu(x): return np.maximum(0, x)

def softmax(x):
    e_x = np.exp(x - np.max(x))
    return e_x / np.sum(e_x)

def batch_norm(x, gamma, beta, mean, var, eps=1e-5):
    return gamma * (x - mean) / np.sqrt(var + eps) + beta

def max_pool(x, size=2, stride=2):
    n, h, w, c = x.shape
    out_h, out_w = (h - size) // stride + 1, (w - size) // stride + 1
    pooled = np.zeros((n, out_h, out_w, c))
    for i in range(out_h):
        for j in range(out_w):
            h_start, h_end = i * stride, i * stride + size
            w_start, w_end = j * stride, j * stride + size
            pooled[:, i, j, :] = np.max(x[:, h_start:h_end, w_start:w_end, :], axis=(1, 2))
    return pooled

def conv2d(x, kernel, bias, padding='same'):
    n, h, w, c_in = x.shape
    k_h, k_w, _, c_out = kernel.shape
    if padding == 'same':
        pad_h, pad_w = (k_h - 1) // 2, (k_w - 1) // 2
        x = np.pad(x, ((0, 0), (pad_h, pad_h), (pad_w, pad_w), (0, 0)))
    out = np.zeros((n, h, w, c_out))
    for i in range(h):
        for j in range(w):
            region = x[:, i:i+k_h, j:j+k_w, :]
            for k in range(c_out):
                out[:, i, j, k] = np.sum(region * kernel[:, :, :, k], axis=(1, 2, 3)) + bias[k]
    return out

def flatten(x): return x.reshape(x.shape[0], -1)

def dense(x, w, b): return np.dot(x, w) + b

def load_weights(layer_type, layer_idx):
    base = f"{weights_dir}/layer_{layer_idx}"
    if layer_type in ['conv', 'dense']:
        k_shape = tuple(map(int, open(f"{base}_kernel_shape.txt").read().split()))
        b_shape = tuple(map(int, open(f"{base}_bias_shape.txt").read().split()))
        k_data = np.loadtxt(f"{base}_kernel.txt").reshape(k_shape)
        b_data = np.loadtxt(f"{base}_bias.txt").reshape(b_shape)
        return k_data, b_data
    elif layer_type == 'bn':
        gamma = np.loadtxt(f"{base}_gamma.txt").reshape(-1)
        beta = np.loadtxt(f"{base}_beta.txt").reshape(-1)
        mean = np.loadtxt(f"{base}_moving_mean.txt").reshape(-1)
        var = np.loadtxt(f"{base}_moving_variance.txt").reshape(-1)
        return gamma, beta, mean, var

# Load image
if not os.path.exists(image_path): raise FileNotFoundError(f"{image_path} not found.")
img = Image.open(image_path).resize((32, 32)).convert("RGB")
x = np.array(img).astype("float32") / 255.0
x = np.expand_dims(x, axis=0)

# === MODEL LAYER TYPES from Keras ===
keras_layers = [
    'conv', 'bn', 'conv', 'bn', 'pool', 'drop',
    'conv', 'bn', 'conv', 'bn', 'pool', 'drop',
    'conv', 'bn', 'conv', 'bn', 'pool', 'drop',
    'flatten',
    'dense', 'bn', 'drop',
    'dense'
]

model_layer_idx = 0  # matches Keras .layers index

for layer_type in keras_layers:
    if layer_type == 'conv':
        k, b = load_weights('conv', model_layer_idx)
        x = relu(conv2d(x, k, b))
    elif layer_type == 'bn':
        g, be, m, v = load_weights('bn', model_layer_idx)
        x = batch_norm(x, g, be, m, v)
    elif layer_type == 'pool':
        x = max_pool(x)
    elif layer_type == 'flatten':
        x = flatten(x)
    elif layer_type == 'dense':
        w, b = load_weights('dense', model_layer_idx)
        x = relu(dense(x, w, b)) if model_layer_idx != 22 else dense(x, w, b)
    elif layer_type == 'drop':
        pass  # dropout ignored at inference
    model_layer_idx += 1  # advance for filename index every time

# Final softmax
x = softmax(x[0])

# Display
pred_class = np.argmax(x)
plt.imshow(img)
plt.axis('off')
plt.title(f"Predicted: {class_labels[pred_class]}")
plt.show()
