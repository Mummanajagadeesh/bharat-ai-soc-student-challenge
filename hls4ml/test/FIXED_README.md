# HLS4ML with Keras 3 - WORKING SETUP ✅

## Problem Solved
The original `convert.py` was missing a critical step: **explicitly calling `hls_model.write()`** after conversion. In hls4ml >= 1.0, the `convert_from_keras_model()` function no longer automatically writes the project files to disk.

## Working Package Versions
```
tensorflow_cpu  2.20.0
keras           3.13.2
hls4ml          1.2.0
numpy           2.4.2
h5py            3.15.1
```

## What Was Changed
Added `hls_model.write()` after the conversion call in `convert.py`:

```python
# Convert to HLS project (NO compile, NO synth)
hls_model = hls4ml.converters.convert_from_keras_model(
    model,
    hls_config=config,
    output_dir="hls4ml_prj",
    part="xc7z020clg400-1",
    backend="Vivado"
)

# Write the HLS project to disk (required for hls4ml >= 1.0)
hls_model.write()  # ← THIS LINE WAS MISSING!
```

## Verified Workflow

### 1. View Model Summary
```bash
cd hls4ml/test
python summary.py
```
✅ Works perfectly - loads Keras 3 model and displays architecture

### 2. Convert to HLS4ML
```bash
# Delete old project if exists
rm -rf hls4ml_prj

# Run conversion
python convert.py
```
✅ Successfully generates HLS project with:
- `hls4ml_prj/` directory
- Firmware C++ code (`firmware/myproject.cpp`)
- Weight files (`firmware/weights/`)
- Build scripts (`build_lib.sh`, `build_prj.tcl`)
- TCL scripts for Vivado synthesis
- Configuration (`hls4ml_config.yml`)

### 3. Generated Files
```
hls4ml_prj/
├── build_lib.sh           # C++ compilation script
├── build_prj.tcl          # Vivado HLS build script
├── vivado_synth.tcl       # Vivado synthesis script
├── project.tcl            # Project configuration
├── firmware/
│   ├── myproject.cpp      # Main HLS C++ implementation
│   ├── myproject.h        # Header file
│   ├── defines.h          # Layer definitions
│   ├── parameters.h       # Network parameters
│   ├── weights/           # Weight files (*.h and *.txt)
│   ├── nnet_utils/        # HLS utility functions
│   └── ap_types/          # Arbitrary precision types
├── hls4ml_config.yml      # Complete configuration
├── keras_model.keras      # Original model copy
├── myproject_test.cpp     # C++ testbench
├── myproject_bridge.cpp   # Python bridge
└── tb_data/               # Testbench data
```

### 4. Build Options (requires Vivado HLS installed)

#### Option A: Build C++ Library (for simulation)
```bash
cd hls4ml_prj
bash build_lib.sh
```
Note: Requires `g++` compiler

#### Option B: Run HLS Synthesis (requires Vivado HLS)
```bash
cd hls4ml_prj
vivado_hls -f build_prj.tcl
```

#### Option C: Run Full Synthesis (requires Vivado)
```bash
cd hls4ml_prj
vivado -mode batch -source vivado_synth.tcl
```

## Configuration Details

### Global Settings
- **Precision**: `ap_fixed<16,6>` (16-bit fixed point, 6 integer bits)
- **ReuseFactor**: 8 (resource sharing)
- **Strategy**: Latency (optimize for low latency)
- **Backend**: Vivado
- **Target**: xc7z020clg400-1 (Zynq-7000 FPGA)

### Layer-Specific Settings
- **Conv2D layers**: `ap_fixed<14,6>`, ReuseFactor=16
- **Add layers**: `ap_fixed<16,6>`
- **Dense layers**: ReuseFactor=1

## Model Architecture
Successfully converted ResNet-style CNN:
- Input: 32×32×3
- 2 residual blocks with skip connections
- Conv2D + BatchNorm + ReLU
- MaxPooling2D layers
- GlobalAveragePooling2D
- Dense output (10 classes)
- Total params: 157,868

## Key Insights

1. **Keras 3 Compatibility**: hls4ml 1.2.0 supports Keras 3, but requires explicit `write()` call
2. **Model Loading**: Use `tf.keras.models.load_model("model.keras")` - works with Keras 3 format
3. **Config Generation**: `config_from_keras_model()` works correctly with Keras 3 models
4. **No Breaking Changes**: The configuration API remains the same

## Troubleshooting

### Issue: "HLS project generated successfully" but no directory
**Solution**: Add `hls_model.write()` after conversion

### Issue: g++ not found when running build_lib.sh
**Solution**: Install g++ or skip C++ simulation (HLS synthesis doesn't need it)
```bash
sudo yum install gcc-c++  # RHEL/Fedora
sudo apt install g++      # Debian/Ubuntu
```

### Issue: Vivado tools not found
**Solution**: Source Vivado settings (only needed for HLS synthesis)
```bash
source /tools/Xilinx/Vivado/<version>/settings64.sh
```

## Next Steps

1. ✅ Model loads correctly
2. ✅ HLS project generates successfully
3. ⏭️ Install Vivado HLS to run synthesis
4. ⏭️ Verify RTL generation
5. ⏭️ Run C-simulation and C/RTL co-simulation
6. ⏭️ Analyze resource utilization and timing

## Success! 🎉
The HLS4ML setup is now fully working with Keras 3. The conversion process completes successfully and generates all necessary files for FPGA synthesis.
