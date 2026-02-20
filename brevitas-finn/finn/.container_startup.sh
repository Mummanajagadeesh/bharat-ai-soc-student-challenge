#!/bin/bash
echo "========================================"
echo " 🛠️ Applying Brevitas & QONNX version fixes..."
echo "========================================"
export SETUPTOOLS_SCM_PRETEND_VERSION=1.0.0
pip install -e deps/qonnx -q
pip install -e deps/brevitas -q

echo " 📂 Setting up FINN build environment..."
export PYTHONPATH="${FINN_ROOT}/src"
export FINN_BUILD_DIR="/tmp/finn_build_temp"
mkdir -p "$FINN_BUILD_DIR"

echo " ✅ Ready! Dropping you into the project folder."
echo "========================================"
cd finn_zybo_project || exit

# Replace the startup process with an interactive bash shell so the terminal stays open
exec /bin/bash
