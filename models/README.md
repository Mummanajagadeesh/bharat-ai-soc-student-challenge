# CNN Model Architectures for CIFAR-10

This repository contains multiple CNN architectures explored for CIFAR-10 classification, progressively optimized for hardware efficiency, reduced parameter count, and FPGA suitability.

All models were trained using data augmentation and Adam optimizer. The progression focuses on reducing FLOPs, parameters, and hardware complexity while maintaining reasonable accuracy.

---

## MODEL_ARCH_1 — `CIFAR10`

* 64 → 128 → 256 convolution blocks
* Batch Normalization + ReLU
* Dense(512) + Softmax
* Parameters: ~3.25M
* Accuracy: 90.91%
* FLOPs: 276.5M

This is the full-capacity baseline model.
Highest accuracy but not hardware-friendly due to size and compute cost.

---

## MODEL_ARCH_2 — `CIFAR_LITE`

* 32 → 64 → 128 convolution blocks
* Batch Normalization retained
* Dense(256)
* Parameters: ~0.82M
* Accuracy: 88.84%
* FLOPs: 99.7M

Reduced version of MODEL_ARCH_1 with significant parameter drop while keeping strong accuracy.

---

## MODEL_ARCH_3 — `CIFAR_LITE_NO_BN`

* 32 → 64 → 96 convolution blocks
* BatchNorm removed
* Dense(256)
* Parameters: ~0.52M
* Accuracy: 85.53%
* FLOPs: 68.2M

BN removed to simplify inference hardware and reduce floating-point operations.

---

## MODEL_ARCH_4 — `CIFAR_LITE_NO_BN_FD`

* 16 → 32 → 64 convolution blocks
* Global Average Pooling (GAP)
* Dense(10)
* Parameters: ~72.7K
* Accuracy: 83.05%
* FLOPs: 20.4M

Fully Dense layer removed and replaced with GAP.
Major reduction in parameters. Suitable for embedded systems.

---

## MODEL_ARCH_5 — `CIFAR_LITE_NO_BN_FD_LITE`

* 16 → 32 conv blocks only
* GAP + Dense(10)
* Parameters: ~17K
* Accuracy: 67.94%
* FLOPs: 7.2M

Extremely lightweight model.
Very small footprint but accuracy drops significantly.

---

## MODEL_ARCH_6 — `CIFAR_LITE_NO_BN_FD_LITE_F`

* 32 → 64 conv blocks
* GAP + Dense(10)
* Parameters: ~66K
* Accuracy: 78.92%
* FLOPs: 13.8M

Improved representational capacity over MODEL_ARCH_5 while staying compact.

---

## MODEL_ARCH_7 — `CIFAR_LITE_NO_BN_FD_LITE_R`

* Residual connections introduced
* 1×1 shortcut convolutions
* 32 → 64 residual blocks
* GAP + Dense(10)
* Parameters: ~68K
* Accuracy: 81.08%
* FLOPs: 15.2M

Residual structure improves gradient flow and accuracy without large parameter growth.
Good balance between efficiency and performance.

---

## MODEL_ARCH_8 — `CIFAR_LITE_NO_BN_FD_2856_R`

* Residual structure retained
* Reduced filters: 28 → 56
* GAP + Dense(10)
* Parameters: ~52.6K
* Accuracy: 80.45%
* FLOPs: 12.6M

Optimized residual model.
Best trade-off between compactness and accuracy among custom lightweight models.

---

## MODEL_ARCH_S — `CIFAR_LITE_BREVITAS`

This version is designed for quantization-aware training using Brevitas.

* Same lightweight residual backbone
* Quantized activations and weights
* Hardware-aligned design for FPGA
* Target: integer / fixed-point inference

This architecture is intended for deployment in hardware accelerators and represents the transition from floating-point training models to FPGA-ready quantized networks.

---

# Architecture Evolution Summary

The design progression follows this path:

Large Accurate Model
→ Reduced Filters
→ Remove BatchNorm
→ Replace Dense with GAP
→ Reduce Depth
→ Reintroduce Accuracy via Residuals
→ Quantization-Aware Model (Brevitas)

The final architectures focus on:

* Lower memory footprint
* Reduced FLOPs
* Hardware compatibility
* Structured residual flow
* Quantization readiness
