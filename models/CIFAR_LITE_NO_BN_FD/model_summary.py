from tensorflow.keras.models import load_model

# Load the saved model
model = load_model("model.keras")  

# Print the model summary
model.summary()