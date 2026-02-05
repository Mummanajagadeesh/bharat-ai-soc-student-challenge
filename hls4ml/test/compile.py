import hls4ml
import tensorflow as tf
from tensorflow.keras.models import load_model, model_from_json
import shutil
import os

# 1. Load and Modify Model Metadata
print("Loading model and stripping softmax...")
orig_model = load_model("model.keras")

# Get model architecture as a dictionary
model_config = orig_model.get_config()

# Find the last layer and force its activation to 'linear'
# This works for both Sequential and Functional models
last_layer_name = model_config['layers'][-1]['name']
if 'activation' in model_config['layers'][-1]['config']:
    model_config['layers'][-1]['config']['activation'] = 'linear'
    print(f"Set activation of {last_layer_name} to linear.")

# Create a new model from this modified config
model = tf.keras.Model.from_config(model_config)

# Copy the weights from the original model to the new "linear" model
model.set_weights(orig_model.get_weights())

print("\nModel restructured successfully. Final layer is now linear.")

# 2. Setup HLS Config
output_dir = "hls4ml_model"
if os.path.exists(output_dir):
    shutil.rmtree(output_dir)

# Define HLS configuration
config = hls4ml.utils.config_from_keras_model(model, granularity='name')
# Apply global fixed-point precision to avoid the ap_private warnings
config['Model']['Precision'] = 'ap_fixed<16,6>'

# 3. Convert and Compile
print("\nConverting to HLS (Softmax logic is now bypassed)...")
hls_model = hls4ml.converters.convert_from_keras_model(
    model,
    hls_config=config,
    output_dir=output_dir,
    part="xc7z010clg400-1"
)

hls_model.write()

print("\nStarting C++ Compilation...")
try:
    hls_model.compile()
    print("\n" + "="*50)
    print("SUCCESS: HLS project compiled!")
    print(f"Output directory: {output_dir}")
    print("Reminder: Hardware output is now 'Logits' (Raw scores).")
    print("="*50)
except Exception as e:
    print(f"\nCompilation Error: {e}")