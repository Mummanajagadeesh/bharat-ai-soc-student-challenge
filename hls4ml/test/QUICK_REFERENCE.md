# Quick Reference: HLS4ML with Keras 3

## ✅ WORKING - The Fix

The issue was that `hls_model.write()` was missing. Here's the corrected code:

```python
import tensorflow as tf
import hls4ml

# Load model
model = tf.keras.models.load_model("model.keras")

# Create config
config = hls4ml.utils.config_from_keras_model(model, granularity="name")
config["Model"]["Precision"] = "ap_fixed<16,6>"
config["Model"]["ReuseFactor"] = 8
config["Model"]["Strategy"] = "Latency"

# Convert
hls_model = hls4ml.converters.convert_from_keras_model(
    model,
    hls_config=config,
    output_dir="hls4ml_prj",
    part="xc7z020clg400-1",
    backend="Vivado"
)

# ⚠️ CRITICAL: Must explicitly write the project!
hls_model.write()  # ← THIS WAS MISSING
```

## Working Versions
```
tensorflow==2.20.0  # (or tensorflow-cpu)
keras==3.13.2
hls4ml==1.2.0
numpy==2.4.2
```

## Usage

```bash
# 1. View model
python summary.py

# 2. Convert to HLS (delete old project first)
rm -rf hls4ml_prj
python convert.py

# 3. Validate everything worked
bash validate_setup.sh

# 4. Build (requires g++)
cd hls4ml_prj
bash build_lib.sh

# 5. Run HLS synthesis (requires Vivado HLS)
vivado_hls -f build_prj.tcl
```

## What Changed in hls4ml 1.x

In older versions (<1.0), `convert_from_keras_model()` automatically wrote files.

In hls4ml >= 1.0, you must:
1. Call `convert_from_keras_model()` to create the model graph
2. Call `hls_model.write()` to write files to disk

## Common Issues

### "Project generated successfully" but no directory
**Cause**: Missing `hls_model.write()`  
**Fix**: Add `hls_model.write()` after conversion

### Keras 2 vs Keras 3
Both work with hls4ml 1.2.0, but:
- Keras 2: Integrated in TensorFlow 2.x
- Keras 3: Standalone package, multi-backend support
- Use `tf.keras.models.load_model()` for both

## File Structure

```
hls4ml_prj/
├── firmware/
│   ├── myproject.cpp     # Main HLS implementation
│   ├── parameters.h      # Network parameters
│   ├── defines.h         # Type definitions
│   ├── weights/          # Weight arrays
│   └── nnet_utils/       # HLS utilities
├── build_prj.tcl         # HLS synthesis script
├── build_lib.sh          # C++ compile script
└── hls4ml_config.yml     # Configuration
```

## Verification Checklist

- [x] Model loads with `tf.keras.models.load_model()`
- [x] Config generates with `config_from_keras_model()`
- [x] Conversion completes without errors
- [x] `hls_model.write()` creates project directory
- [x] Firmware C++ code exists
- [x] Weight files created
- [x] Build scripts present
- [x] Config YAML written

---

**Status**: ✅ Fully Working  
**Tested**: 2024-02-02  
**Platform**: RHEL/Fedora Linux
