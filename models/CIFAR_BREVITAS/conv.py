import tensorflow as tf
import tf2onnx
import onnx

# 1. Load your Keras model
model = tf.keras.models.load_model('model_2_15.keras') 

# 2. Convert to ONNX
spec = (tf.TensorSpec((None, *model.input_shape[1:]), tf.float32, name="input"),)
output_path = "model.onnx"

model_proto, _ = tf2onnx.convert.from_keras(model, input_signature=spec, opset=13)
onnx.save(model_proto, output_path)

print(f"Success! Model saved to {output_path}")
