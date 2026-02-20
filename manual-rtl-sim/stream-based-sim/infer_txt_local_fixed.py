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
# FIXED POINT CONFIG (Q1.7)
# ===============================
FRAC_BITS = 7
SCALE = 1 << FRAC_BITS  # 128

# ===============================
# LOAD IMAGE FROM TXT (ONE IMAGE)
# ===============================
def load_image_from_txt(image_txt_dir):
    r = np.loadtxt(os.path.join(image_txt_dir, "image_r.txt"), dtype=np.float32)
    g = np.loadtxt(os.path.join(image_txt_dir, "image_g.txt"), dtype=np.float32)
    b = np.loadtxt(os.path.join(image_txt_dir, "image_b.txt"), dtype=np.float32)

    img = np.stack([r, g, b], axis=-1)   # (32,32,3)

    # 🔴 FIX: MATCH PNG PIPELINE
    img = img / 255.0

    img = np.expand_dims(img, axis=0)    # (1,32,32,3)
    return img

# ===============================
# LOAD FIXED-POINT WEIGHTS
# ===============================
def load_kernel_file_fixed(filename, shape):
    kh, kw, ic, oc = shape
    kernel = np.zeros(shape, dtype=np.float32)

    with open(filename, "r") as f:
        lines = [l.strip() for l in f if l.strip()]

    idx = 0
    for i in range(kh):
        for j in range(kw):
            for c in range(ic):
                vals = [int(v) / SCALE for v in lines[idx].split()]
                kernel[i, j, c, :] = vals
                idx += 1
    return kernel

def load_weights_fixed(layer_name, shape):
    kfile = f"model_weights_fixed8/{layer_name}_kernel.txt"
    bfile = f"model_weights_fixed8/{layer_name}_bias.txt"

    if len(shape) == 4:
        kernel = load_kernel_file_fixed(kfile, shape)
    else:
        kernel = np.loadtxt(kfile, dtype=np.int32).reshape(shape) / SCALE

    bias = np.loadtxt(bfile, dtype=np.int32) / SCALE
    return kernel, bias

# ===============================
# NN OPS
# ===============================
def relu(x):
    return np.maximum(0, x)

def pad_input(x, p):
    return np.pad(x, ((0,0),(p,p),(p,p),(0,0)), mode="constant")

def conv2d(x, kernel, bias, stride=1):
    b, h, w, ic = x.shape
    kh, kw, _, oc = kernel.shape
    pad = kh // 2
    x = pad_input(x, pad)

    out = np.zeros((b, h, w, oc), dtype=np.float32)

    for n in range(b):
        for i in range(h):
            for j in range(w):
                region = x[n, i:i+kh, j:j+kw, :]
                for c in range(oc):
                    out[n,i,j,c] = np.sum(region * kernel[:,:,:,c]) + bias[c]
    return out

def max_pool(x):
    b, h, w, c = x.shape
    out = np.zeros((b, h//2, w//2, c), dtype=np.float32)

    for n in range(b):
        for i in range(0, h, 2):
            for j in range(0, w, 2):
                out[n, i//2, j//2, :] = np.max(x[n, i:i+2, j:j+2, :], axis=(0,1))
    return out

def global_avg_pool(x):
    return np.mean(x, axis=(1,2))

def dense(x, w, b):
    return np.dot(x, w) + b

# ===============================
# MODEL FORWARD
# ===============================
def run_inference(x, W):
    a = relu(conv2d(x, *W["01_conv2d"]))
    a = relu(conv2d(a, *W["02_conv2d_1"]))
    s = conv2d(x, *W["03_conv2d_2"])
    x = max_pool(a + s)

    a = relu(conv2d(x, *W["06_conv2d_3"]))
    a = relu(conv2d(a, *W["07_conv2d_4"]))
    s = conv2d(x, *W["08_conv2d_5"])
    x = max_pool(a + s)

    x = global_avg_pool(x)
    x = dense(x, *W["12_dense"])
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

weights = {}
for name, shape in weight_shapes.items():
    weights[name] = load_weights_fixed(name, shape)

# ===============================
# RUN
# ===============================
img = load_image_from_txt("image_txt")
logits = run_inference(img, weights)
pred = int(np.argmax(logits))

print("Logits:", logits[0])
print("Prediction:", pred, "-", label_map[pred])
