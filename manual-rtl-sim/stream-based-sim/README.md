
# Stream-based Version (AXI-MM + AXI-Stream + First Layer Conv)

This directory contains the hardware infrastructure used to move from pure RTL simulation toward FPGA-ready modular CNN acceleration.

It is divided into three main blocks:

* `wtinp/` — AXI-MM weight & bias loader
* `imginp/` — AXI-Stream image pipeline (DDR → DMA → RGB packer)
* `conv/` — Parametric convolution core and full first-layer proof-of-concept

All modules are handwritten RTL. All functionality is verified using self-checking testbenches.

---

# 1. wtinp — AXI-MM Weight & Bias Loader

This folder implements a minimal AXI4-Lite read master to load:

* Convolution weights
* Convolution biases

from memory into internal RTL storage.

## Modules

* `axi_simple_mem.v` — AXI memory model
* `axi_weight_bias_loader.v` — AXI read master
* `weight_bias_loader.v` — Generic memory interface version
* `tb_axi_weight_bias_loader.v` — Testbench

The loader:

* Reads W_COUNT weights
* Then reads B_COUNT biases
* Uses ARVALID/ARREADY and RVALID/RREADY handshake
* Stores data internally as signed 8-bit

---

## Run Simulation

From inside `wtinp/`:

```
iverilog -o test axi_weight_bias_loader.v axi_simple_mem.v tb_axi_weight_bias_loader.v
vvp test
```

Expected output:

* First 16 weights printed
* All biases printed
* Comparison against expected `.mem` files
* PASS message

Example:

```
[PASS] AXI-MM weight & bias loader verified
```

This confirms:

* Correct AXI read sequencing
* Correct address mapping
* Correct internal storage

---

# 2. imginp — AXI-Stream Image Pipeline

This folder implements a streaming image pipeline:

DDR → DMA → Byte FIFO → RGB Packer → Sink

It verifies correct reconstruction of RGB pixels from planar memory layout.

## Architecture

### DDR Model

`ddr_mem_dualport.v`

* Byte-addressable memory
* Configurable read latency
* Dual-port interface

### DMA Engine

`dma_read.v`

* Issues read requests
* Maintains outstanding transactions
* Pushes responses into FIFO
* Produces AXI-Stream byte output

### Byte FIFO

`byte_fifo.v`

* Backpressure-aware FIFO
* Implements ready/valid protocol

### RGB Packer

`axis_rgb_packer.v`

* Receives R plane
* Then G plane
* Then B plane
* Reconstructs 24-bit RGB pixels
* Generates TLAST at frame end

### Verification Testbench

`tb_axis_rgb_packer_verify.v`

* Loads image_r.mem
* Loads image_g.mem
* Loads image_b.mem
* Verifies first 16 packed pixels

---

## Run Simulation

From inside `imginp/`:

```
iverilog -o test ddr_mem_dualport.v dma_read.v byte_fifo.v conv1_image_sink.v axis_rgb_packer.v tb_axis_rgb_packer.v
vvp test
```

Expected output:

```
PIX 0 | R=131 G=125 B=125 | TLAST=0 | EXP_R=131 EXP_G=125 EXP_B=125
...
[PASS] RGB packing verified
```

This verifies:

* Correct DMA memory traversal
* Correct streaming behavior
* Proper FIFO backpressure
* Correct RGB pixel reconstruction
* Proper TLAST signaling

---

# 3. conv — Parametric Convolution Core

This folder contains two implementations:

1. Parametric streaming 3×3 convolution core
2. Full first-layer implementation (proof-of-concept)

---

## 3.1 Parametric Streaming conv_3x3

### Core Components

* `pe.v` — Processing Element (Multiply unit)
* `conv.v` — Line-buffer + sliding window + MAC tree
* `conv_tb.v` — Testbench

### Architecture

* Three line buffers
* Sliding 3×3 window
* 9 PEs (parallel multiply)
* Pipelined add tree
* 3-stage valid pipeline

---

## Run Parametric Conv Test

From inside `conv/`:

```
iverilog -o test conv.v pe.v conv_tb.v
vvp test
```

Expected output:

```
OUT = 537
OUT = 582
...
OUT = 1977
```

This verifies:

* Correct sliding window behavior
* Correct multiply-accumulate
* Proper pipeline timing
* Deterministic convolution output

---

# 3.2 Full First Layer Implementation (Proof of Concept)

File:

```
conv_full_layer1.v
```

This implementation:

* Loads image from text files
* Loads 3×3×3×28 kernels
* Loads 28 biases
* Performs full convolution
* Applies fixed-point normalization
* Applies ReLU
* Dumps all 28 feature maps to files

---

## Run Full First Layer

From inside `conv/`:

```
iverilog -o test conv_full_layer1.v
vvp test
```

Expected output:

```
Loading images...
Loading kernel...
Loading bias...
Starting convolution...
Filter 0 done.
...
Filter 27 done.
All 28 feature maps generated.
```

Output feature maps stored in:

```
conv_res/feature_map_X.txt
```

---

# Golden Comparison

Python (Golden) Example:

```
0 17 0 0 0 55 22 ...
```

Verilog Generated:

```
0 17 0 0 0 56 23 ...
```

Small ±1 differences are due to:

* Integer rounding
* Fixed-point scaling
* Division by 255 normalization

This confirms:

* Numerically correct fixed-point implementation
* Matching structural behavior
* Valid first-layer RTL proof-of-concept

---

# Directory Structure Summary

```
wtinp/      → AXI-MM weight loader
imginp/     → DDR + DMA + AXI-Stream image pipeline
conv/       → Parametric conv core + full first layer
```

---

# What Is Proven

1. AXI-MM read master works correctly
2. DDR → DMA → AXI-Stream pipeline works
3. RGB packing verified
4. Parametric streaming convolution works
5. Full first CNN layer works with fixed-point arithmetic
6. Feature maps match Python golden (minor rounding deviation)

---

# Status

* First layer fully functional
* AXI-MM weight loading verified
* AXI-Stream image pipeline verified
* Streaming convolution validated
* Full first-layer proof-of-concept complete

This forms the complete hardware foundation required for integrating CNN acceleration onto FPGA.
