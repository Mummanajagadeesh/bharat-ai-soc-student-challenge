import numpy as np
import cv2
import os
import matplotlib.pyplot as plt
from matplotlib.gridspec import GridSpec

# --- CONFIG ---
class_names = ['airplane', 'automobile', 'bird', 'cat', 'deer',
               'dog', 'frog', 'horse', 'ship', 'truck']

weights_dir = "weights_txt"
image_path = "sample_images/airplane/airplane_2.png"
layers = [
    'conv', 'bn', 'conv', 'bn', 'pool', 'drop',
    'conv', 'bn', 'conv', 'bn', 'pool', 'drop',
    'conv', 'bn', 'conv', 'bn', 'pool', 'drop',
    'flatten', 'dense', 'bn', 'drop', 'dense'
]

# --- Load image ---
img = cv2.imread(image_path)
if img is None:
    raise FileNotFoundError(f"Image not found at {image_path}")

img = cv2.resize(img, (32, 32))
img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB).astype(np.float32) / 255.0
x = img_rgb.transpose(2, 0, 1)  # CHW
feature_maps = {'original': x.copy()}

# --- Utility functions ---
def load_weights(layer_type, idx):
    base = f"{weights_dir}/layer_{idx}"
    if layer_type == 'conv' or layer_type == 'dense':
        k = np.loadtxt(f"{base}_kernel.txt")
        b = np.loadtxt(f"{base}_bias.txt")
        ks = tuple(map(int, open(f"{base}_kernel_shape.txt").read().split()))
        bs = tuple(map(int, open(f"{base}_bias_shape.txt").read().split()))
        k = k.reshape(ks)
        b = b.reshape(bs)
        return k, b
    elif layer_type == 'bn':
        gamma = np.loadtxt(f"{base}_gamma.txt")
        beta = np.loadtxt(f"{base}_beta.txt")
        mean = np.loadtxt(f"{base}_moving_mean.txt")
        var = np.loadtxt(f"{base}_moving_variance.txt")
        return gamma, beta, mean, var

def conv2d(x, kernel, bias, pad='same'):
    c_out, c_in, k_h, k_w = kernel.shape
    h, w = x.shape[1], x.shape[2]
    out = np.zeros((c_out, h, w))

    if pad == 'same':
        pad_h, pad_w = k_h // 2, k_w // 2
        x_padded = np.pad(x, ((0, 0), (pad_h, pad_h), (pad_w, pad_w)), mode='constant')
    else:
        x_padded = x
        h = h - k_h + 1
        w = w - k_w + 1
        out = np.zeros((c_out, h, w))

    for i in range(c_out):
        for j in range(c_in):
            filtered = cv2.filter2D(x_padded[j], -1, kernel[i, j])
            if pad == 'same':
                filtered = filtered[pad_h:pad_h+h, pad_w:pad_w+w]
            out[i] += filtered
        out[i] += bias[i]
    return out

def batch_norm(x, gamma, beta, mean, var, eps=1e-5):
    return gamma[:, None, None] * (x - mean[:, None, None]) / np.sqrt(var[:, None, None] + eps) + beta[:, None, None]

def relu(x): return np.maximum(0, x)

def max_pool(x, size=2, stride=2):
    c, h, w = x.shape
    out_h, out_w = h // size, w // size
    pooled = np.zeros((c, out_h, out_w))
    for i in range(out_h):
        for j in range(out_w):
            h_start, h_end = i * stride, i * stride + size
            w_start, w_end = j * stride, j * stride + size
            pooled[:, i, j] = np.max(x[:, h_start:h_end, w_start:w_end], axis=(1, 2))
    return pooled

def flatten(x): return x.reshape(-1)

def dense(x, w, b): return np.dot(x, w) + b

# --- Run model layer-by-layer ---
idx = 0
stage_names = ['original']
for layer in layers:
    if layer == 'conv':
        k, b = load_weights('conv', idx)
        k = k.transpose(3, 2, 0, 1) if k.ndim == 4 else k.T
        x = conv2d(x, k, b)
        stage_names.append(f"conv{idx}")
        feature_maps[f"conv{idx}"] = x.copy()
    elif layer == 'bn':
        g, beta, mean, var = load_weights('bn', idx)
        x = batch_norm(x, g, beta, mean, var)
        stage_names.append(f"bn{idx}")
        feature_maps[f"bn{idx}"] = x.copy()
        x = relu(x)
        stage_names.append(f"relu{idx}")
        feature_maps[f"relu{idx}"] = x.copy()
    elif layer == 'pool':
        x = max_pool(x)
        stage_names.append(f"pool{idx}")
        feature_maps[f"pool{idx}"] = x.copy()
    elif layer == 'flatten':
        x = flatten(x)
        stage_names.append(f"flatten{idx}")
        feature_maps[f"flatten{idx}"] = x.copy()
    elif layer == 'dense':
        w, b = load_weights('dense', idx)
        x = dense(x, w, b)
        if idx != 22:
            x = relu(x)
            stage_names.append(f"dense_relu{idx}")
        else:
            stage_names.append(f"dense_out")
        feature_maps[stage_names[-1]] = x.copy()
    elif layer == 'drop':
        pass  # ignored
    idx += 1

# --- Visualization ---
current_idx = 0
fig = plt.figure(figsize=(12, 12))  # Global figure

def update_visual(stage):
    fig.clf()
    fig.suptitle(stage, fontsize=16)
    data = feature_maps[stage]

    if data.ndim == 1:
        ax = fig.add_subplot(1, 1, 1)
        if stage == 'dense_out':
            pred_idx = np.argmax(data)
            ax.bar(range(len(data)), data, color='gray')
            ax.bar(pred_idx, data[pred_idx], color='red')
            ax.set_title(f"Prediction: {class_names[pred_idx]} (logit = {data[pred_idx]:.2f})")
        else:
            ax.plot(data)
            ax.set_title("Dense Output")
        fig.canvas.draw_idle()
        return

    if data.shape[0] == 3 and stage == 'original':
        ax = fig.add_subplot(1, 1, 1)
        ax.imshow(data.transpose(1, 2, 0))
        ax.axis('off')
        fig.canvas.draw_idle()
        return

    c = data.shape[0]
    grid_size = int(np.ceil(np.sqrt(c)))
    gs = GridSpec(grid_size, grid_size, figure=fig)
    for i in range(c):
        ax = fig.add_subplot(gs[i // grid_size, i % grid_size])
        ax.imshow(data[i], cmap='gray')
        ax.axis('off')
    fig.canvas.draw_idle()

def on_key(event):
    global current_idx
    if event.key == 'right':
        current_idx = (current_idx + 1) % len(stage_names)
    elif event.key == 'left':
        current_idx = (current_idx - 1) % len(stage_names)
    update_visual(stage_names[current_idx])

print(f"Use ← → arrow keys to navigate through {len(stage_names)} stages.")
fig.canvas.mpl_connect('key_press_event', on_key)
update_visual(stage_names[current_idx])
plt.show()
