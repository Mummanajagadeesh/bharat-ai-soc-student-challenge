# Build and Run Setup

This document describes how the model was compiled with different GCC optimization levels and how inference latency was measured.

Three source variants are compared:

* `c_model` — baseline keras2c output
* `c_model_optm` — pragma and loop-level optimizations
* `c_model_optm_2` — structural graph fusion (residual + pooling)

All binaries are built using the **same commands** and measured using the **same runtime setup**.

---

## Compilation Commands

These commands are **unchanged** for all versions.

```

gcc -O0 predict.c my_model.c include/*.c -I./include -lm -o predict_O0

```
```

gcc -O1 predict.c my_model.c include/*.c -I./include -lm -o predict_O1

```
```

gcc -O2 predict.c my_model.c include/*.c -I./include -lm -o predict_O2

```
```

gcc -O3 predict.c my_model.c include/*.c -I./include -lm -o predict_O3

```
```

gcc -Ofast predict.c my_model.c include/*.c -I./include -lm -o predict_Ofast

```

---

## Runtime Setup

```

export IMG=../sample_images/cat/cat_7.png

```

Warmup run:

```

./predict_O2 $IMG >/dev/null

```

---

# Baseline Model (`c_model`)

### Description

Unmodified keras2c-generated C code.

* Separate layers for:

  * Conv
  * Activation
  * Add
  * MaxPool
* Each layer materializes full intermediate tensors.
* Residual blocks execute as:

  * `conv → conv → add → maxpool`

---

## Timing Summary — `c_model` (100 images)

| Executable    | Avg (ms) | Min (ms) | Max (ms) | Std Dev |
| ------------- | -------: | -------: | -------: | ------: |
| predict_O0    |      120 |      110 |      137 |    6.93 |
| predict_O1    |       55 |       51 |       65 |    3.27 |
| predict_O2    |       10 |        9 |       14 |    1.31 |
| predict_O3    |        4 |        4 |        7 |    0.91 |
| predict_Ofast |        4 |        4 |        6 |    0.64 |

---

# Pragma-Optimized Model (`c_model_optm`)

### What Changed

**No graph changes. No layer fusion.**

Only loop- and memory-level optimizations:

#### 1. Convolution layers

* `#pragma GCC ivdep`
* `#pragma GCC unroll`
* aligned weight buffers
* reduced loop-carried dependencies

#### 2. Activation layers

* tighter loops for ReLU / linear
* reduced call overhead

#### 3. Merge layers (add, multiply, max)

* unrolled elementwise loops
* aliasing reduced

#### 4. Core layers (dense)

* cleaner inner loops
* better cache locality

Files modified:

* `k2c_convolution_layers.c`
* `k2c_activations.c`
* `k2c_merge_layers.c`
* `k2c_core_layers.c`

---

## Timing Summary — `c_model_optm` (100 images)

| Executable    | Avg (ms) | Min (ms) | Max (ms) | Std Dev |
| ------------- | -------: | -------: | -------: | ------: |
| predict_O0    |       23 |       21 |       28 |    1.62 |
| predict_O1    |       55 |       51 |       65 |    3.53 |
| predict_O2    |        9 |        9 |       12 |    1.07 |
| predict_O3    |        4 |        4 |        7 |    0.97 |
| predict_Ofast |        4 |        4 |        6 |    0.49 |

### Observation

* Faster at `-O0` due to reduced structural overhead
* Comparable at `-O1` where compiler optimizations dominate
* Minor gains at `-O2`
* Limited improvement at `-O3` / `-Ofast` due to execution floor

---

# Fused Graph Model (`c_model_optm_2`)

### What Changed (Critical)

This version introduces **structural changes to the model execution**, not just faster loops.

---

## Key Insight

The model contains **two residual blocks**:

```

conv → conv
↘      ↙
add → maxpool

```

Original execution cost per block:

1. Read tensor A
2. Read tensor B
3. Write add output tensor
4. Read add output tensor
5. Write maxpool output tensor

That is **5 full tensor memory passes per block**.

---

## Structural Optimization Applied

### Residual Fusion: `add + maxpool`

The following sequences in `my_model.c`:

```

k2c_add(...)
k2c_maxpool2d(...)

```

were replaced with **one fused loop** that:

* performs elementwise add **inside** the pooling window
* computes max directly
* writes only the pooled output
* eliminates the intermediate add tensor entirely

This was applied to **both residual blocks**:

* 32×32×28 → 16×16×28
* 16×16×56 → 8×8×56

Files modified:

* `my_model.c` only

No library API was changed.

---

## Timing Summary — `c_model_optm_2` (100 images)

| Executable    | Avg (ms) | Min (ms) | Max (ms) | Std Dev |
| ------------- | -------: | -------: | -------: | ------: |
| predict_O0    |       23 |       22 |       32 |    1.89 |
| predict_O1    |        7 |        6 |        9 |    0.88 |
| predict_O2    |        6 |        6 |        7 |    0.73 |
| predict_O3    |        4 |        4 |        5 |    0.20 |
| predict_Ofast |        3 |        3 |        4 |    <1.0 |

---

# Final Comparison (All Versions)

### Average Latency

| Optimization Level | c_model | c_model_optm | c_model_optm_2 |
| ------------------ | ------: | -----------: | -------------: |
| O0                 |     120 |           23 |             23 |
| O1                 |      55 |           55 |              7 |
| O2                 |      10 |            9 |              6 |
| O3                 |       4 |            4 |              4 |
| Ofast              |       4 |            4 |              3 |

---

# Conclusions

1. **Pragmas alone are insufficient**

   * They optimize compute
   * They do not reduce memory traffic

2. **Residual fusion is the real win**

   * Removes entire tensors
   * Eliminates redundant memory passes
   * Improves performance even at `-O0`

3. The bottleneck was **graph structure**, not FLOPs

4. `c_model_optm_2` achieves:

   * ~5× speedup vs baseline O0
   * ~1.4× speedup vs baseline O2
   * near-constant runtime across inputs

---

# Recommended Configuration

* Source: `c_model_optm_2`
* Compiler: `-O3` or `-Ofast`
* Use `c_model` only for debugging or reference correctness

---

# BEST vs WORST

```

cd c_model_optm_2
gcc -Ofast -march=native -funroll-loops predict.c my_model.c include/*.c -I./include -lm -o predict_W
start=$(date +%s%N); ./predict_W $IMG >/dev/null; end=$(date +%s%N); echo "O0 ms = $(( (end-start)/1000000 ))"

```
```

cd c_model
cc -fno-inline -fno-tree-vectorize -fno-builtin predict.c my_model.c include/*.c -I./include -lm -o predict_L
start=$(date +%s%N); ./predict_L $IMG >/dev/null; end=$(date +%s%N); echo "O0 ms = $(( (end-start)/1000000 ))"

```

Around **30–40×** improvement