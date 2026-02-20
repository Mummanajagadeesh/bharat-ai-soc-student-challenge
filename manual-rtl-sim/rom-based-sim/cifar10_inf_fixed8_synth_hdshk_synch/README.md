# CIFAR-10 Fixed-Point RTL (Synthesizable, Handshake + Synchronous Version)

This directory contains the synthesizable, handshake-based, fully synchronous fixed-point implementation of the CIFAR-10 CNN.

Unlike the earlier monolithic simulation model, this version:

* Uses memory-based weight loading
* Uses explicit start/done handshaking
* Separates layers into independently testable RTL blocks
* Generates ROM and `.mem` files for synthesis
* Allows layer-by-layer validation

All arithmetic is fixed-point (Q1.7, SCALE = 128).

---

## One-Time Setup

### 1. Generate Fixed-Point Weights + ROM Files

```bash
python fixed_hdshk.py
```

This performs:

* Fixed-point conversion (overflow count reported)
* Reconstruction verification
* Verilog ROM generation
* `.mem` file generation

Generated directories:

```
model_weights_fixed8
model_weights_2
verilog_roms_mems_hdshk
```

---

### 2. Create Output Folder for Layer 0

One time:

```bash
mkdir 00_conv2d_w_br
```

This directory stores output feature maps from the first convolution layer.

---

## Image Preparation

Convert image to RGB memory format:

```bash
python img2rgb.py
```

Output:

```
image_roms_mem_hdshk/
image_txt/
```

---

## Running First Convolution Layer (Layer 0)

Compile:

```bash
iverilog -o test 00_conv2d_hdshk.v \
verilog_roms_mems_hdshk/00_conv2d_*.v \
image_roms_mem_hdshk/*.v \
00_tb_hdshk.v
```

Run:

```bash
vvp test
```

Expected output:

* Feature maps written to:

```
00_conv2d_w_br/feature_map_*.txt
```

Example console output:

```
Starting conv2d_mem_tb...
Opened 00_conv2d_w_br/feature_map_0.txt
-> Wrote feature_map_0.txt
...
conv2d_mem_tb completed.
```

You can now visually compare these generated feature maps with:

```
relu_0/
```

These should match after fixed-point rounding effects.

---

## Running Second Convolution Layer

After validating Layer 0:

Compile corresponding second layer files:

Example:

```bash
iverilog -o test 01_conv2d_hdshk.v \
verilog_roms_mems_hdshk/01_conv2d_*.v \
01_tb_hdshk.v
```

Run:

```bash
vvp test
```

Generated feature maps can be compared against:

```
relu_1/
```

---

## Adding Layers Sequentially

The project is structured so that each layer can be:

1. Compiled independently
2. Verified independently
3. Compared against Python fixed-point reference

Layer progression:

| Layer        | RTL File             | Reference Directory |
| ------------ | -------------------- | ------------------- |
| Conv0 + ReLU | `00_conv2d_hdshk.v`  | `relu_0/`           |
| Conv1 + ReLU | `01_conv2d_hdshk.v`  | `relu_1/`           |
| MaxPool      | `02_maxpool_hdshk.v` | `max_pool_1/`       |
| Conv Block 2 | `03_conv2d_hdshk.v`  | `relu_2/`           |
| GAP          | `09_gap_new.v`       | `global_avg_pool/`  |
| Dense        | `10_dense_new.v`     | `dense_logits/`     |
| Softmax      | `11_softmax_new.v`   | `softmax/`          |

Each stage produces output `.txt` files that can be directly compared with Python-generated ground truth.

---

## Full Directory Highlights

* `verilog_roms_mems_hdshk/`
  Auto-generated ROM modules and memory files

* `image_roms_mem_hdshk/`
  Image memory ROM modules

* `*_w_br/`
  Per-layer output feature maps

* `relu_*`, `max_pool_*`, `softmax/`
  Python fixed-point reference outputs

* `vis_fixed_single_new.py`
  Visual comparison script (single image)

* `vis_fixed_all_new.py`
  Visual comparison script (all layers)

---

## Design Characteristics

* Fully synchronous
* Explicit start/done handshake between layers
* Synthesizable structure
* ROM-based weight storage
* Layer-by-layer validation
* Fixed-point arithmetic (Q1.7)

---

## Purpose of This Directory

This version serves as:

* A synthesizable CNN pipeline
* A handshake-driven RTL architecture
* A layer-by-layer verification environment
* A bridge between software validation and hardware deployment

Each layer is validated independently before integrating into the full pipeline, ensuring correctness at every stage.

---

This directory represents the synthesizable, memory-based, handshake-driven fixed-point CNN implementation with full intermediate verification support.
