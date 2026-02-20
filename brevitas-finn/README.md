# Brevitas to FINN: Zybo Z7-10 FPGA Deployment Workflow

## Overview

This directory documents the complete end-to-end workflow for deploying a quantized neural network to the Digilent Zybo Z7-10 FPGA using:

* PyTorch
* Xilinx Brevitas (quantization-aware training)
* QONNX export
* FINN compiler
* Vivado 2022.2

The pipeline converts a trained quantized PyTorch model into a synthesizable hardware accelerator and produces a deployable `.bit` bitstream for the Zybo Z7-10 (Zynq-7000).

---

## 1. Model Architecture and Quantization Strategy

A custom ResNet-style architecture was designed specifically to fit within the DSP, LUT, and BRAM constraints of the Zynq-7000 (xc7z010clg400-1).

### Quantization Scheme

* **Input Quantization**

  * 8-bit signed
  * Implemented using a quantized identity layer
  * Ensures correct scaling before first convolution

* **Weight Quantization**

  * 4-bit signed
  * Applied to all convolutional and linear layers
  * Reduces memory footprint and BRAM usage

* **Activation Quantization**

  * 4-bit unsigned
  * Applied to ReLU layers
  * Ensures compatibility with FINN's hardware mapping constraints

### Hardware-Friendly Design Choices

* MaxPool layers used instead of floating-point reductions
* No unsupported floating-point operations
* Strictly integer arithmetic pipeline
* Structured residual blocks for efficient hardware mapping

---

## 2. Training Pipeline

### Dataset

* CIFAR-10
* All images resized to 28×28
* Matches hardware input dimensions

### Training Configuration

* 30 epochs
* GPU acceleration
* Optimized DataLoader configuration:

  * Pinned memory
  * Multiple CPU workers
  * cuDNN benchmarking enabled

### Export to QONNX

After training:

* Model weights saved
* Network traced
* Exported to FINN-compatible QONNX format
* Used `QONNXManager` for export

Output:

* Quantized `.onnx` / `.qonnx` model ready for FINN

---

## 3. FINN Environment Configuration

The FINN Docker container was customized for stability and performance.

### I/O Optimization

* Build directory redirected to:

  ```
  /tmp
  ```
* Uses RAM disk inside container
* Avoids host filesystem latency during:

  * Verilator simulation
  * C++ compilation
  * Intermediate artifact generation

### Dependency Control

* Ensured specific compatible versions of:

  * Brevitas
  * QONNX
* Installed automatically at container startup

---

## 4. Custom Zybo Z7-10 Board Integration

Zybo Z7-10 is not officially supported by default FINN releases.

Manual modifications were required.

### Board Injection

Added:

* Part number: `xc7z010clg400-1`
* AXI port width: 32-bit
* Architecture: `zynq_7000`

### Synthesis Template Adjustments

* Modified TCL templates
* Ensured correct PS–PL wiring
* Enabled AXI-Stream and AXI-Lite integration
* Bypassed legacy 10-interface AXI-Lite limitation

  * Required for multi-layer ResNet configuration registers

---

## 5. FINN Compilation Flow

The exported QONNX model was passed through FINN’s 17-step dataflow compilation pipeline.

### Major Stages

1. Model transformation and cleanup
2. Streamlining
3. Folding and parallelization decisions
4. HLS IP generation
5. RTL IP generation
6. Verilator simulation
7. Dataflow stitching
8. Vivado block design generation
9. Synthesis
10. Place and Route
11. Bitstream generation

---

## 6. Hardware Integration

### IP Generation

* Quantized layers converted into:

  * HLS-based IP blocks
  * RTL blocks
* All integer arithmetic

### System Integration

Generated Vivado Block Design:

* Zynq Processing System (PS)
* FINN accelerator (PL)
* AXI-Stream for data
* AXI-Lite for control

### Memory Stability Fix

Applied:

```
LD_PRELOAD
```

With a native Linux memory allocator override to improve Vivado 2022.2 stability during:

* Synthesis
* Place and Route

---

## 7. Final Output

Successful generation of:

* Hardware handoff file
* `.bit` bitstream
* Ready for deployment via:

  * PYNQ
  * Direct JTAG programming

---

## Summary

This workflow demonstrates:

* End-to-end quantized model deployment
* Custom FINN board integration
* ResNet-style architecture mapping to FPGA
* Successful bitstream generation for Zybo Z7-10

This directory represents the hardware deployment pipeline, distinct from the pure-RTL and pure-software inference implementations in other parts of the repository.
