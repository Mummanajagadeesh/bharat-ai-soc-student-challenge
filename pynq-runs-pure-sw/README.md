# Pure Software CNN Inference (PYNQ ARM Baseline)

This directory contains the pure NumPy-based software implementation of the CNN model executed directly on the PYNQ board (ARM Cortex-A9 processor). No FPGA acceleration is used in this baseline.

The purpose of this experiment is to establish a CPU-only performance reference for comparison with the hardware-accelerated implementation.

---

## Files

* `infer_txt_localds.py`
  Floating-point inference baseline

* `infer_txt_localds_fixed.py`
  Fixed-point (Q1.7) inference baseline

* `model_weights/`
  Floating-point weights

* `model_weights_fixed8/`
  Quantized fixed-point weights (8-bit, Q1.7)

* `sample_images/`
  100 CIFAR-10 test images (10 per class)

---

## System

Executed directly on:

* PYNQ Board
* Zynq ARM Cortex-A9 Processor
* Linux environment
* Python + NumPy

Note: A modern laptop CPU would execute the same NumPy implementation in well under one second per image. The embedded ARM processor is significantly slower and is used intentionally to demonstrate the need for hardware acceleration.

---

## How to Run

From this directory:

### Floating-Point Baseline

```bash
python infer_txt_localds.py
```

Results will be saved to:

```
results_txt.txt
```

---

### Fixed-Point (Q1.7) Baseline

```bash
python infer_txt_localds_fixed.py
```

Results will be saved to:

```
results_txt_fixed.txt
```

---

## Dataset

* 100 CIFAR-10 images
* 10 images per class
* Resolution: 32×32 RGB
* Total classes: 10

---

## Results Summary

### Floating-Point Baseline

| Metric             | Value          |
| ------------------ | -------------- |
| Total Images       | 100            |
| Correct            | 84             |
| Accuracy           | 84%            |
| Min Time (ms)      | 21111.040      |
| Max Time (ms)      | 21472.352      |
| Avg Time (ms)      | 21182.881      |
| Std Dev (ms)       | 58.962         |
| Avg Time per Image | ~21.18 seconds |

---

### Fixed-Point (Q1.7) Baseline

| Metric             | Value          |
| ------------------ | -------------- |
| Total Images       | 100            |
| Correct            | 84             |
| Accuracy           | 84%            |
| Min Time (ms)      | 29610.999      |
| Max Time (ms)      | 30207.396      |
| Avg Time (ms)      | 29703.500      |
| Std Dev (ms)       | 75.307         |
| Avg Time per Image | ~29.70 seconds |

---

## Observations

* Both floating-point and fixed-point implementations achieve identical classification accuracy (84%).
* The fixed-point software version is slower due to scaling and conversion overhead.
* Average inference time on the ARM Cortex-A9 processor is 21–30 seconds per image.
* This confirms that CPU-only execution on the embedded ARM processor is not suitable for real-time inference.
* These results serve as the baseline for evaluating FPGA acceleration speedup.

---

This directory strictly represents the software-only baseline used for performance comparison against the hardware-accelerated CNN implementation.
