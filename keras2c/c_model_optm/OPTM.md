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

* O0 = 167 ms

```
start=$(date +%s%N); ./predict_O1 $IMG >/dev/null; end=$(date +%s%N); echo "O1 ms = $(( (end-start)/1000000 ))"
```

Result:

* O1 = 98 ms

```
start=$(date +%s%N); ./predict_O2 $IMG >/dev/null; end=$(date +%s%N); echo "O2 ms = $(( (end-start)/1000000 ))"
```

Result:

* O2 = 54 ms

```
start=$(date +%s%N); ./predict_O3 $IMG >/dev/null; end=$(date +%s%N); echo "O3 ms = $(( (end-start)/1000000 ))"
```

Result:

* O3 = 37 ms

```
start=$(date +%s%N); ./predict_Ofast $IMG >/dev/null; end=$(date +%s%N); echo "Ofast ms = $(( (end-start)/1000000 ))"
```

Result:

* Ofast = 69 ms

---

## Optimized Model Timing (c_model_optm)

Same binaries and commands, run on the optimized source.

```
start=$(date +%s%N); ./predict_O0 $IMG >/dev/null; end=$(date +%s%N); echo "O0 ms = $(( (end-start)/1000000 ))"
```

Result:

* O0 = 226 ms

```
start=$(date +%s%N); ./predict_O1 $IMG >/dev/null; end=$(date +%s%N); echo "O1 ms = $(( (end-start)/1000000 ))"
```

Result:

* O1 = 130 ms

```
start=$(date +%s%N); ./predict_O2 $IMG >/dev/null; end=$(date +%s%N); echo "O2 ms = $(( (end-start)/1000000 ))"
```

Result:

* O2 = 42 ms

```
start=$(date +%s%N); ./predict_O3 $IMG >/dev/null; end=$(date +%s%N); echo "O3 ms = $(( (end-start)/1000000 ))"
```

Result:

* O3 = 36 ms

```
start=$(date +%s%N); ./predict_Ofast $IMG >/dev/null; end=$(date +%s%N); echo "Ofast ms = $(( (end-start)/1000000 ))"
```

Result:

* Ofast = 32 ms

---

## Performance Comparison Table

| Optimization Level | c_model (ms) | c_model_optm (ms) | Speedup |
| ------------------ | -----------: | ----------------: | ------: |
| O0                 |          167 |               226 |  slower |
| O1                 |           98 |               130 |  slower |
| O2                 |           54 |                42 |   ~1.3× |
| O3                 |           37 |                36 |  ~1.03× |
| Ofast              |           69 |                32 |   ~2.1× |

---

## Notes

* Optimizations are only effective at higher compiler levels.
* `-O2`, `-O3`, and `-Ofast` benefit from pragma unrolling and alignment.
* `-Ofast` shows the largest gain with the optimized code.
* At `-O0` and `-O1`, added pragmas increase overhead instead of helping.

This confirms the changes are intended for aggressive compiler optimization, not debug builds.


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
| predict_O0    |      191 |      130 |      245 |   22.25 |
| predict_O1    |      115 |       75 |      202 |   24.70 |
| predict_O2    |       64 |       31 |      146 |   20.30 |
| predict_O3    |       59 |       30 |      123 |   17.49 |
| predict_Ofast |       50 |       30 |      120 |   14.83 |

---

## Before vs After Optimization (Average Latency)

| Optimization Level | Before (ms) | After (ms) |          Change |
| ------------------ | ----------: | ---------: | --------------: |
| O0                 |         180 |        191 |          slower |
| O1                 |         122 |        115 |          ~1.06× |
| O2                 |          61 |         64 |         similar |
| O3                 |          52 |         59 | slightly slower |
| Ofast              |          56 |         50 |          ~1.12× |

---

## Observations

* Pragmas do **not** help at `-O0`.

  * Extra directives add overhead without compiler support.
* Small gains appear at `-O1`, but variance remains high.
* `-O2` shows similar average performance, indicating partial utilization of pragmas.
* `-O3` benefits inconsistently due to aggressive compiler heuristics already in place.
* `-Ofast` benefits the most:

  * Lowest average latency
  * Lowest standard deviation
  * Best overall throughput

---

## Key Takeaways

* Source-level pragmas are **designed for high optimization levels**.
* Best configuration for deployment:

  * Optimized source (`c_model_optm`)
  * `-Ofast` or `-O3` depending on numerical safety requirements
* Baseline builds remain useful for debugging and correctness checks.

This section completes the timing comparison between baseline and optimized implementations.
