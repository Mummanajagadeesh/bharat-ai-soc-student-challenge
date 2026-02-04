# Import necessary libraries
import hls4ml
import tensorflow as tf
from keras.models import load_model

# Load the Keras model from the specified path
my_model = load_model('model.keras')

# Print a header indicating the start of model configuration output
print("Configuration of given model:--------------------------------------------------------------------------------------------")

# Generate configuration for HLS conversion from the Keras model
config = hls4ml.utils.config_from_keras_model(my_model, granularity='model')

# Print the generated configuration
print(config)

# Print a footer indicating the end of model configuration output
print("-----------------------------------------------------------------------------------------------")

# Convert the Keras model to an HLS model using the specified configuration
hls_model = hls4ml.converters.convert_from_keras_model(
    my_model, hls_config=config, output_dir=r'hls4ml_model', part='xc7z010clg400-1'
)

# Print a separator before the build step
print("--------------------------------------------------------------------------------------------------")

# Build the HLS model (without CSIM)
hls_model.build(csim=False)