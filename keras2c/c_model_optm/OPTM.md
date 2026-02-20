## Build and Run Setup

This document describes how the model was compiled with different GCC optimization levels and how inference latency was measured.
Two versions are compared:

* baseline `c_model`
* optimized `c_model_optm` (with pragma and memory changes)

---

## Compilation Commands

Each binary is built with a different GCC optimization flag.

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

Input image is provided using an environment variable.

```

export IMG=../sample_images/cat/cat_7.png

```

A warmup run is done to avoid cold-start effects.

```

./predict_O2 $IMG >/dev/null

```

---

## Baseline Model Timing (c_model)

Each run measures end-to-end inference time in milliseconds.

```

start=$(date +%s%N); ./predict_O0 $IMG >/dev/null; end=$(date +%s%N); echo "O0 ms = $(( (end-start)/1000000 ))"

```

Result:

* O0 = 120 ms

```

start=$(date +%s%N); ./predict_O1 $IMG >/dev/null; end=$(date +%s%N); echo "O1 ms = $(( (end-start)/1000000 ))"

```

Result:

* O1 = 55 ms

```

start=$(date +%s%N); ./predict_O2 $IMG >/dev/null; end=$(date +%s%N); echo "O2 ms = $(( (end-start)/1000000 ))"

```

Result:

* O2 = 10 ms

```

start=$(date +%s%N); ./predict_O3 $IMG >/dev/null; end=$(date +%s%N); echo "O3 ms = $(( (end-start)/1000000 ))"

```

Result:

* O3 = 4 ms

```

start=$(date +%s%N); ./predict_Ofast $IMG >/dev/null; end=$(date +%s%N); echo "Ofast ms = $(( (end-start)/1000000 ))"

```

Result:

* Ofast = 4 ms

---

## Optimized Model Timing (c_model_optm)

Same binaries and commands, run on the optimized source.

```

start=$(date +%s%N); ./predict_O0 $IMG >/dev/null; end=$(date +%s%N); echo "O0 ms = $(( (end-start)/1000000 ))"

```

Result:

* O0 = 23 ms

```

start=$(date +%s%N); ./predict_O1 $IMG >/dev/null; end=$(date +%s%N); echo "O1 ms = $(( (end-start)/1000000 ))"

```

Result:

* O1 = 55 ms

```

start=$(date +%s%N); ./predict_O2 $IMG >/dev/null; end=$(date +%s%N); echo "O2 ms = $(( (end-start)/1000000 ))"

```

Result:

* O2 = 9 ms

```

start=$(date +%s%N); ./predict_O3 $IMG >/dev/null; end=$(date +%s%N); echo "O3 ms = $(( (end-start)/1000000 ))"

```

Result:

* O3 = 4 ms

```

start=$(date +%s%N); ./predict_Ofast $IMG >/dev/null; end=$(date +%s%N); echo "Ofast ms = $(( (end-start)/1000000 ))"

```

Result:

* Ofast = 4 ms

---

## Performance Comparison Table

| Optimization Level | c_model (ms) | c_model_optm (ms) | Speedup |
| ------------------ | -----------: | ----------------: | ------: |
| O0                 |          120 |                23 |   ~5.2× |
| O1                 |           55 |                55 | similar |
| O2                 |           10 |                 9 |   ~1.1× |
| O3                 |            4 |                 4 | similar |
| Ofast              |            4 |                 4 | similar |

---

## Notes

* Major gains are observed at `-O0`, indicating structural and algorithmic improvements.
* At `-O1`, performance remains unchanged, suggesting compiler optimizations already dominate.
* `-O2` shows minor improvements with optimized source.
* `-O3` and `-Ofast` reach a hardware or algorithmic performance floor.
* Optimizations primarily reduce unoptimized-path overhead rather than affecting peak-optimized builds.

---

## Detailed Timing Report (After Optimization Using Pragmas)

This section extends the timing analysis by adding results **after applying source-level optimizations** (alignment, `#pragma GCC ivdep`, loop unrolling).
The optimized build is referred to as `c_model_optm`.

All benchmarks were executed using:

```

chmod +x compare.sh
./compare.sh

```

The same image set, execution order, and measurement method are used as in the baseline to keep results comparable.

---

## Timing Summary Table (After Optimization)

| Executable    | Avg (ms) | Min (ms) | Max (ms) | Std Dev |
| ------------- | -------: | -------: | -------: | ------: |
| predict_O0    |       23 |       21 |       28 |    1.62 |
| predict_O1    |       55 |       51 |       65 |    3.27 |
| predict_O2    |        9 |        9 |       12 |    1.07 |
| predict_O3    |        4 |        4 |        7 |    0.97 |
| predict_Ofast |        4 |        4 |        6 |    0.64 |

---

## Before vs After Optimization (Average Latency)

| Optimization Level | Before (ms) | After (ms) |          Change |
| ------------------ | ----------: | ---------: | --------------: |
| O0                 |         120 |         23 |        ~5.2×    |
| O1                 |          55 |         55 |        similar  |
| O2                 |          10 |          9 |        ~1.1×    |
| O3                 |           4 |          4 |        similar  |
| Ofast              |           4 |          4 |        similar  |

---

## Observations

* Structural optimizations significantly reduce unoptimized execution cost.
* Compiler optimizations dominate at `-O1` and above.
* `-O2` benefits marginally from improved memory layout and reduced instruction count.
* `-O3` and `-Ofast` show no additional gains, indicating saturation of the execution pipeline.

---

## Key Takeaways

* Source-level optimizations primarily benefit low or partially optimized builds.
* Best configuration for deployment:

  * Optimized source (`c_model_optm`)
  * `-O3` or `-Ofast` when latency floor is acceptable
* Baseline builds remain useful for debugging and validation.

This section completes the timing comparison between baseline and optimized implementations.
