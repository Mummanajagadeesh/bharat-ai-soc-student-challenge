import numpy as np
import os

# ===============================
# CIFAR-10 LABELS
# ===============================
label_map = {
    0: "airplane", 1: "automobile", 2: "bird", 3: "cat", 4: "deer",
    5: "dog", 6: "frog", 7: "horse", 8: "ship", 9: "truck"
}

# ===============================
# FIXED-POINT CONFIG (Q1.7)
# ===============================
WEIGHT_FRAC_BITS = 7
WEIGHT_SCALE = 1 << WEIGHT_FRAC_BITS

ACT_FRAC_BITS = 7
ACT_SCALE = 1 << ACT_FRAC_BITS

DUMP_ROOT = "py-golden"
COL_WIDTH = 6

# ===============================
# SAVE (SAME FORMAT AS BEFORE)
# ===============================
def save_2d_int_pretty(path, arr):
    with open(path, "w") as f:
        for row in arr:
            f.write(" ".join(f"{int(v):{COL_WIDTH}d}" for v in row) + "\n")

# ===============================
# FIXED-POINT (MATCHES 2nd CODE)
# ===============================
def quantize_dump_dequant_q17(x, layer_name):
    layer_dir = os.path.join(DUMP_ROOT, layer_name)
    os.makedirs(layer_dir, exist_ok=True)

    # === EXACTLY LIKE 2nd SCRIPT ===
    x_q = (x * ACT_SCALE).astype(np.int64)

    if x.ndim == 4:
        for ch in range(x.shape[-1]):
            save_2d_int_pretty(
                os.path.join(layer_dir, f"ch_{ch:03d}.txt"),
                x_q[0, :, :, ch]
            )
    else:
        save_2d_int_pretty(
            os.path.join(layer_dir, "vector.txt"),
            x_q.reshape(1, -1)
        )

    return x_q.astype(np.float32) / ACT_SCALE

# ===============================
# LOAD IMAGE
# ===============================
def load_image_from_txt(image_txt_dir):
    r = np.loadtxt(os.path.join(image_txt_dir, "image_r.txt"), dtype=np.uint8)
    g = np.loadtxt(os.path.join(image_txt_dir, "image_g.txt"), dtype=np.uint8)
    b = np.loadtxt(os.path.join(image_txt_dir, "image_b.txt"), dtype=np.uint8)

    img = np.stack([r, g, b], axis=-1).astype(np.float32)
    img /= 255.0
    return img[np.newaxis, ...]

# ===============================
# LOAD WEIGHTS
# ===============================
def load_kernel_file_fixed(filename, shape):
    kh, kw, ic, oc = shape
    kernel = np.zeros(shape, dtype=np.float32)
    with open(filename) as f:
        lines = [l.strip() for l in f if l.strip()]
    idx = 0
    for i in range(kh):
        for j in range(kw):
            for c in range(ic):
                kernel[i, j, c, :] = [
                    int(v) / WEIGHT_SCALE for v in lines[idx].split()
                ]
                idx += 1
    return kernel

def load_weights_fixed(layer_name, shape):
    kfile = f"model_weights_fixed8/{layer_name}_kernel.txt"
    bfile = f"model_weights_fixed8/{layer_name}_bias.txt"

    if len(shape) == 4:
        kernel = load_kernel_file_fixed(kfile, shape)
    else:
        kernel = np.loadtxt(kfile, dtype=np.int32).reshape(shape) / WEIGHT_SCALE

    bias = np.loadtxt(bfile, dtype=np.int32) / WEIGHT_SCALE
    return kernel, bias

# ===============================
# NN OPS
# ===============================
def relu(x):
    return np.maximum(0, x)

def pad_input(x, p):
    return np.pad(x, ((0,0),(p,p),(p,p),(0,0)))

def conv2d(x, kernel, bias):
    b, h, w, _ = x.shape
    kh, kw, _, oc = kernel.shape
    pad = kh // 2
    x = pad_input(x, pad)

    out = np.zeros((b, h, w, oc), dtype=np.float32)
    for n in range(b):
        for i in range(h):
            for j in range(w):
                region = x[n, i:i+kh, j:j+kw, :]
                for c in range(oc):
                    out[n, i, j, c] = np.sum(region * kernel[..., c]) + bias[c]
    return out

def max_pool(x):
    b, h, w, c = x.shape
    out = np.zeros((b, h//2, w//2, c), dtype=np.float32)
    for n in range(b):
        for i in range(0, h, 2):
            for j in range(0, w, 2):
                out[n, i//2, j//2] = np.max(
                    x[n, i:i+2, j:j+2], axis=(0,1)
                )
    return out

def global_avg_pool(x):
    return np.mean(x, axis=(1,2))

def dense(x, w, b):
    return np.dot(x, w) + b

# ===============================
# MODEL FORWARD
# ===============================
def run_inference(x, W):
    os.makedirs(DUMP_ROOT, exist_ok=True)

    y = quantize_dump_dequant_q17(conv2d(x, *W["01_conv2d"]), "01_conv2d")
    a = quantize_dump_dequant_q17(relu(y), "01_conv2d_relu")

    y = quantize_dump_dequant_q17(conv2d(a, *W["02_conv2d_1"]), "02_conv2d_1")
    a = quantize_dump_dequant_q17(relu(y), "02_conv2d_1_relu")

    s = quantize_dump_dequant_q17(conv2d(x, *W["03_conv2d_2"]), "03_conv2d_2")
    x = quantize_dump_dequant_q17(max_pool(a + s), "04_maxpool")

    y = quantize_dump_dequant_q17(conv2d(x, *W["06_conv2d_3"]), "06_conv2d_3")
    a = quantize_dump_dequant_q17(relu(y), "06_conv2d_3_relu")

    y = quantize_dump_dequant_q17(conv2d(a, *W["07_conv2d_4"]), "07_conv2d_4")
    a = quantize_dump_dequant_q17(relu(y), "07_conv2d_4_relu")

    s = quantize_dump_dequant_q17(conv2d(x, *W["08_conv2d_5"]), "08_conv2d_5")
    x = quantize_dump_dequant_q17(max_pool(a + s), "09_maxpool")

    x = quantize_dump_dequant_q17(global_avg_pool(x), "10_gap")
    x = quantize_dump_dequant_q17(dense(x, *W["12_dense"]), "12_dense")

    return x

# ===============================
# LOAD WEIGHTS
# ===============================
weight_shapes = {
    "01_conv2d":   (3,3,3,28),
    "02_conv2d_1": (3,3,28,28),
    "03_conv2d_2": (1,1,3,28),
    "06_conv2d_3": (3,3,28,56),
    "07_conv2d_4": (3,3,56,56),
    "08_conv2d_5": (1,1,28,56),
    "12_dense":    (56,10),
}

weights = {
    k: load_weights_fixed(k, s)
    for k, s in weight_shapes.items()
}

# ===============================
# RUN
# ===============================
img = load_image_from_txt("image_txt")
logits = run_inference(img, weights)
pred = int(np.argmax(logits))

print("Logits:", logits[0])
print("Prediction:", pred, "-", label_map[pred])
