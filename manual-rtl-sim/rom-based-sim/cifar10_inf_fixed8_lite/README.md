# CIFAR-10 RTL Inference (Fixed-Point, Fully Modular Verilog)

This directory contains the fully modular Verilog implementation of the CIFAR-10 CNN model using fixed-point arithmetic (Q1.7 scaling, SCALE = 128).

The design is written in pure Verilog and structured using separate modules:

* `conv2d_module`
* `maxpool_module`
* `avgpool_module`
* `dense_module`

The top-level module is:

```
cifar10_top
```

All computation is performed in RTL. Python is used only for preprocessing, weight generation, automation, and result verification.

---

## Directory Structure

```
auto_all.py
auto_single.py
fixed.py
img2rgb.py
cnn_mod.v
cnn_mod_tb.v
cnn_top.v
modular/
    conv.v
    dense.v
    gap.v
    maxpool.v
model_weights_fixed8/
sample_images/
results.txt
```

---

## One-Time Weight Preparation

Generate fixed-point (Q1.7) weights:

```bash
python fixed.py
```

This converts trained weights into fixed-point format and prepares memory files used by the RTL design.

This step only needs to be done once.

---

## Single Image Manual Flow

### Step 1 — Copy Image

```bash
cp sample_images/cat/cat_0.png image.png
```

### Step 2 — Convert Image to RGB Text

```bash
python img2rgb.py
```

This generates input memory files inside `image_txt/`.

### Step 3 — Compile RTL

```bash
iverilog -o test cnn_mod.v modular/*.v
```

### Step 4 — Run Simulation

```bash
vvp test
```

If everything is correct, the predicted class should match the input image (for example, `cat`) when the confidence score (logit) is highest for that class.

---

## Automated Single Image Run

To preprocess and run inference automatically for `image.png`:

```bash
python auto_single.py
```

This script:

* Converts the image
* Loads weights
* Runs RTL simulation
* Extracts prediction
* Displays result

---

## Run All 100 Images

To evaluate all CIFAR-10 test images:

```bash
python auto_all.py
```

This script:

* Iterates over all 100 test images
* Runs full RTL inference for each image
* Compares predicted vs actual label
* Logs results

Full results are saved to:

```
results.txt
```

The file contains:

* Image index
* Predicted label
* Actual label
* Match status

---

## Architecture Overview

The top-level module `cifar10_top` implements:

* Residual Block 1

  * Conv3×3 (3 → 28)
  * Conv3×3 (28 → 28)
  * Shortcut 1×1
  * Addition
  * MaxPool

* Residual Block 2

  * Conv3×3 (28 → 56)
  * Conv3×3 (56 → 56)
  * Shortcut 1×1
  * Addition + ReLU
  * MaxPool

* Global Average Pooling

* Dense Layer (56 → 10)

* Argmax for prediction

All layers operate in fixed-point arithmetic using SCALE = 128.

---

## Prediction Output

After inference:

* `pred_index` holds the predicted class index (0–9)
* `logits0` to `logits9` contain class scores
* Highest logit determines prediction

Example classes:

```
0: airplane
1: automobile
2: bird
3: cat
4: deer
5: dog
6: frog
7: horse
8: ship
9: truck
```

---

## Expected Behavior

* Correct predictions for most images (baseline ~84% accuracy).
* Results should match Python fixed-point inference.
* Minor rounding differences may occur due to integer arithmetic.

---

## Notes

* This is a fully modular pure Verilog implementation.
* No vendor IP cores are used.
* All convolution, pooling, GAP, and dense layers are manually implemented.
* Designed for functional correctness and architectural clarity.

---

This directory represents the complete RTL fixed-point inference engine for CIFAR-10 using modular hardware design.
