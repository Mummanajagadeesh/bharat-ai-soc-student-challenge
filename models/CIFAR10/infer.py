import os
import json
import numpy as np
import tensorflow as tf
from tensorflow.keras.models import model_from_json
from tensorflow.keras.datasets import cifar10
import matplotlib.pyplot as plt

# === 1. Load saved model ===

# Set path to directory where files are saved
save_dir = "model_info"

# Load model architecture
with open(os.path.join(save_dir, "model_architecture.txt"), "r") as f:
    model_json = f.read()
model = model_from_json(model_json)

# Load model weights
model.load_weights(os.path.join(save_dir, "model_weights.weights.h5"))

# Compile model with default config for inference
model.compile(optimizer="adam", loss="categorical_crossentropy", metrics=["accuracy"])

# Load class labels
with open(os.path.join(save_dir, "class_labels.json"), "r") as f:
    class_labels = json.load(f)
class_labels = {int(k): v for k, v in class_labels.items()}

# === 2. Load CIFAR-10 and randomly select 5 images ===
(_, _), (x_test, y_test) = cifar10.load_data()

# Normalize input data
x_test = x_test.astype("float32") / 255.0

# If model expects one-hot labels during training, we only need raw labels for inference

# Random selection
idx = np.random.choice(len(x_test), size=5, replace=False)
sample_images = x_test[idx]
sample_labels = y_test[idx]

# === 3. Run inference ===
predictions = model.predict(sample_images)

# === 4. Show predictions ===
for i in range(5):
    plt.imshow(sample_images[i])
    plt.axis('off')
    pred_class = np.argmax(predictions[i])
    true_class = sample_labels[i][0]
    plt.title(f"Pred: {class_labels.get(pred_class, pred_class)}\nTrue: {class_labels.get(true_class, true_class)}")
    plt.show()