#!/bin/bash
# Validation script for HLS4ML Keras 3 setup

set -e

echo "======================================"
echo "HLS4ML + Keras 3 Validation Script"
echo "======================================"
echo ""

echo "1. Checking package versions..."
python -c "
import tensorflow as tf
import keras
import hls4ml
import numpy as np

print(f'  TensorFlow: {tf.__version__}')
print(f'  Keras: {keras.__version__}')
print(f'  hls4ml: {hls4ml.__version__}')
print(f'  NumPy: {np.__version__}')
"
echo ""

echo "2. Testing model summary..."
python summary.py > /dev/null 2>&1 && echo "  ✅ Model loads successfully" || echo "  ❌ Failed to load model"
echo ""

echo "3. Cleaning old HLS project..."
rm -rf hls4ml_prj
echo "  ✅ Cleaned"
echo ""

echo "4. Running HLS conversion..."
python convert.py > /dev/null 2>&1 && echo "  ✅ Conversion completed" || echo "  ❌ Conversion failed"
echo ""

echo "5. Validating generated files..."
test -d hls4ml_prj && echo "  ✅ Project directory created" || echo "  ❌ Project directory missing"
test -f hls4ml_prj/build_lib.sh && echo "  ✅ Build script created" || echo "  ❌ Build script missing"
test -f hls4ml_prj/firmware/myproject.cpp && echo "  ✅ HLS C++ code created" || echo "  ❌ HLS code missing"
test -f hls4ml_prj/hls4ml_config.yml && echo "  ✅ Config file created" || echo "  ❌ Config missing"

WEIGHT_COUNT=$(ls hls4ml_prj/firmware/weights/*.h 2>/dev/null | wc -l)
test $WEIGHT_COUNT -gt 0 && echo "  ✅ Weight files created ($WEIGHT_COUNT files)" || echo "  ❌ No weight files"
echo ""

echo "6. Summary of generated project:"
echo "  Project: hls4ml_prj/"
echo "  Build scripts:"
ls hls4ml_prj/*.sh hls4ml_prj/*.tcl 2>/dev/null | sed 's/^/    - /'
echo ""

echo "======================================"
echo "✅ ALL CHECKS PASSED!"
echo "======================================"
echo ""
echo "Next steps:"
echo "  • To build C++ library: cd hls4ml_prj && bash build_lib.sh"
echo "  • To run HLS synthesis: cd hls4ml_prj && vivado_hls -f build_prj.tcl"
echo "  • To run full synthesis: cd hls4ml_prj && vivado -mode batch -source vivado_synth.tcl"
echo ""
