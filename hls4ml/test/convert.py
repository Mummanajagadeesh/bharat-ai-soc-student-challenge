import tensorflow as tf
import hls4ml

# Load Keras model
model = tf.keras.models.load_model("model.keras")

# Create hls4ml config
config = hls4ml.utils.config_from_keras_model(
    model,
    granularity="name"
)

# Global settings
config["Model"]["Precision"] = "ap_fixed<16,6>"
config["Model"]["ReuseFactor"] = 8
config["Model"]["Strategy"] = "Latency"

# Layer-level tuning
for layer in config["LayerName"]:
    lname = layer.lower()

    if "conv2d" in lname:
        config["LayerName"][layer]["ReuseFactor"] = 16
        config["LayerName"][layer]["Precision"] = "ap_fixed<14,6>"

    if "add" in lname:
        config["LayerName"][layer]["Precision"] = "ap_fixed<16,6>"

    if "dense" in lname:
        config["LayerName"][layer]["ReuseFactor"] = 1

# Convert to HLS project (NO compile, NO synth)
hls_model = hls4ml.converters.convert_from_keras_model(
    model,
    hls_config=config,
    output_dir="hls4ml_prj",
    part="xc7z020clg400-1",
    backend="Vivado"
)

# Write the HLS project to disk (required for hls4ml >= 1.0)
hls_model.write()

print("HLS project generated successfully.")