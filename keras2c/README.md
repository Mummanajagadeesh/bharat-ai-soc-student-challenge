# CIFAR-10 Inference Benchmark on Zynq-7000 (ARM Cortex-A9)

This document summarizes performance results of three C implementations of the same CNN model executed on a **Xilinx Zynq-7000 SoC**, specifically the **dual-core ARM Cortex-A9 (ARMv7-A)** processing system.

All measurements were performed on the ARM processor (PS), not on FPGA programmable logic.
Each executable was evaluated on **100 CIFAR-10 images (10 per class)**.

---

## Hardware Platform

**Board Class:** Zynq-7000
**Processor:** Dual-core ARM Cortex-A9
**Architecture:** ARMv7-A (32-bit)
**Typical Frequency:** ~650–866 MHz (board dependent)
**Execution Mode:** Single-core user-space execution
**Dataset:** 100 CIFAR-10 images (32×32 RGB)

No FPGA acceleration was used in this benchmark. All inference runs were CPU-only.

---

## Compared Model Variants

Three source versions were evaluated:

1. **c_model**

   * Direct keras2c output
   * Separate Conv, Add, ReLU, MaxPool layers
   * Full intermediate tensors materialized

2. **c_model_optm**

   * Loop pragmas (`ivdep`, `unroll`)
   * Memory alignment improvements
   * No structural graph changes

3. **c_model_optm_2**

   * Residual fusion: `add + maxpool` merged
   * Intermediate tensor removed
   * Memory passes reduced
   * Structural graph optimization

---

## Zynq Timing Summary (100 Images)

#### 1. Baseline — `c_model`

| Optimization | Avg (ms) |  Min |  Max | Std Dev |
| ------------ | -------: | ---: | ---: | ------: |
| O0           |     5526 | 5525 | 5542 |    1.69 |
| O1           |     1480 | 1479 | 1482 |    0.84 |
| O2           |      398 |  394 |  414 |    4.13 |
| O3           |      378 |  373 |  392 |    4.49 |
| Ofast        |      378 |  373 |  388 |    4.11 |

Performance plateau: **~378 ms**

---

#### 2. Pragma Optimized — `c_model_optm`

| Optimization | Avg (ms) |  Min |  Max | Std Dev |
| ------------ | -------: | ---: | ---: | ------: |
| O0           |     5684 | 5672 | 5724 |   13.13 |
| O1           |     1506 | 1501 | 1664 |   17.23 |
| O2           |      447 |  442 |  464 |    5.31 |
| O3           |      422 |  418 |  439 |    5.32 |
| Ofast        |      422 |  417 |  438 |    4.86 |

Performance plateau: **~422 ms**

Observation:
On ARM Cortex-A9, loop pragmas alone do **not** improve performance.
In fact, this version is consistently slower than baseline.

---

#### 3. Fused Graph — `c_model_optm_2`

| Optimization | Avg (ms) | Min | Max | Std Dev |
| ------------ | -------: | --: | --: | ------: |
| O0           |      936 | 934 | 944 |    2.34 |
| O1           |      379 | 373 | 397 |    5.76 |
| O2           |      363 | 358 | 378 |    4.99 |
| O3           |      362 | 358 | 377 |    4.59 |
| Ofast        |      361 | 357 | 377 |    4.39 |

Performance plateau: **~361 ms**

---

## Full Comparison

#### Average Latency (ms)

| Level | c_model | c_model_optm | c_model_optm_2 |
| ----- | ------: | -----------: | -------------: |
| O0    |    5526 |         5684 |            936 |
| O1    |    1480 |         1506 |            379 |
| O2    |     398 |          447 |            363 |
| O3    |     378 |          422 |            362 |
| Ofast |     378 |          422 |            361 |

---

## Speedup Analysis (Zynq ARM)

###### Best Case Comparison (Ofast)

* Baseline: 378 ms
* Fused: 361 ms

Improvement:
~4.5% faster

###### Worst Case Comparison (O0)

* Baseline: 5526 ms
* Fused: 936 ms

Improvement:
~5.9× faster

---

## Key Observations

#### 1. Compiler Optimization Matters (But Has a Ceiling)

Baseline:

* O0 → O1 gives ~3.7× improvement
* O1 → O2 gives ~3.7× improvement
* O2 → O3 minimal gain
* O3 → Ofast negligible gain

Plateau occurs around 370–380 ms.

---

#### 2. Pragmas Alone Do Not Help on Cortex-A9

Unlike x86 laptop results:

* ARM Cortex-A9 has:

  * Smaller cache
  * In-order pipeline
  * Limited speculative execution
  * No aggressive auto-vectorization

Loop unrolling increases pressure without improving memory behavior.

Result:
`c_model_optm` is slower at every level.

---

#### 3. Structural Fusion Is the Real Optimization

The fused model eliminates:

* One full intermediate tensor per residual block
* One entire memory pass
* One large write + read cycle

Original residual cost:
conv → conv → add → maxpool
5 tensor memory passes

Fused residual:
conv → conv → fused_add_pool
3 tensor memory passes

On memory-bound ARM systems, reducing memory traffic is more important than reducing arithmetic operations.

---

## ARM vs Laptop Behavior

On laptop (x86):

* O3 reached ~4 ms
* Fused version achieved large structural gain

On Zynq ARM:

* Plateau around ~360–380 ms
* Much slower cores
* Memory bandwidth dominates
* Structural fusion helps mainly at low optimization levels

---

## Conclusions

1. Zynq-7000 ARM Cortex-A9 is strongly memory-bound for this workload.
2. Compiler flags provide major improvement up to O2.
3. Beyond O2, performance saturates.
4. Loop pragmas alone are ineffective.
5. Graph-level fusion provides:

   * Massive gain at O0
   * Moderate gain at O1
   * Small but consistent gain at O2/O3

---

## Recommended Configuration (Zynq ARM)

Use:

* **Source:** `c_model_optm_2`
* **Compiler:** `-O3`
* Avoid excessive pragmas unless paired with structural changes.

---

## Final Ranking (Best to Worst on Zynq)

1. c_model_optm_2 (Ofast / O3) ~361 ms
2. c_model (O3 / Ofast) ~378 ms
3. c_model_optm (O3 / Ofast) ~422 ms
4. c_model baseline O0 ~5526 ms

---

This confirms:

On embedded ARM systems, reducing memory movement at graph level yields more benefit than micro-optimizing loops.

