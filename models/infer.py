import warnings
import builtins
builtins.original_warn = warnings.warn
warnings.warn = lambda *args, **kwargs: None

import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'

import numpy as np
import tensorflow as tf
tf.get_logger().setLevel('ERROR')

from tensorflow.keras import layers, models
import matplotlib.pyplot as plt
from PIL import Image


# === CONFIG ===
weights_dir = "weights_txt"
image_path = "image.png"

# === Hardcoded class labels ===
class_labels = {
    0: "airplane",
    1: "automobile",
    2: "bird",
    3: "cat",
    4: "deer",
    5: "dog",
    6: "frog",
    7: "horse",
    8: "ship",
    9: "truck"
}

# === Rebuild model architecture ===
def build_model():
    model = models.Sequential()
    model.add(layers.Conv2D(64, (3, 3), padding='same', activation='relu', input_shape=(32, 32, 3)))
    model.add(layers.BatchNormalization())
    model.add(layers.Conv2D(64, (3, 3), padding='same', activation='relu'))
    model.add(layers.BatchNormalization())
    model.add(layers.MaxPooling2D())
    model.add(layers.Dropout(0.3))

    model.add(layers.Conv2D(128, (3, 3), padding='same', activation='relu'))
    model.add(layers.BatchNormalization())
    model.add(layers.Conv2D(128, (3, 3), padding='same', activation='relu'))
    model.add(layers.BatchNormalization())
    model.add(layers.MaxPooling2D())
    model.add(layers.Dropout(0.4))

    model.add(layers.Conv2D(256, (3, 3), padding='same', activation='relu'))
    model.add(layers.BatchNormalization())
    model.add(layers.Conv2D(256, (3, 3), padding='same', activation='relu'))
    model.add(layers.BatchNormalization())
    model.add(layers.MaxPooling2D())
    model.add(layers.Dropout(0.5))

    model.add(layers.Flatten())
    model.add(layers.Dense(512, activation='relu'))
    model.add(layers.BatchNormalization())
    model.add(layers.Dropout(0.5))
    model.add(layers.Dense(10, activation='softmax'))
    return model

# === Load weights from .txt files ===
def load_weights_from_txt(model, weights_dir):
    for i, layer in enumerate(model.layers):
        weights = []

        if isinstance(layer, tf.keras.layers.BatchNormalization):
            for kind in ["gamma", "beta", "moving_mean", "moving_variance"]:
                shape_file = os.path.join(weights_dir, f"layer_{i}_{kind}_shape.txt")
                data_file = os.path.join(weights_dir, f"layer_{i}_{kind}.txt")

                with open(shape_file, "r") as f:
                    shape = tuple(map(int, f.read().split()))
                arr = np.loadtxt(data_file).reshape(shape)
                weights.append(arr)

        elif isinstance(layer, (tf.keras.layers.Conv2D, tf.keras.layers.Dense)):
            for kind in ["kernel", "bias"]:
                shape_file = os.path.join(weights_dir, f"layer_{i}_{kind}_shape.txt")
                data_file = os.path.join(weights_dir, f"layer_{i}_{kind}.txt")

                with open(shape_file, "r") as f:
                    shape = tuple(map(int, f.read().split()))
                arr = np.loadtxt(data_file).reshape(shape)
                weights.append(arr)

        if weights:
            layer.set_weights(weights)

# === Load and preprocess image.png ===
if not os.path.exists(image_path):
    raise FileNotFoundError(f"{image_path} not found.")

img = Image.open(image_path).resize((32, 32)).convert("RGB")
img_array = np.array(img).astype("float32") / 255.0
img_array = np.expand_dims(img_array, axis=0)

# === Build and load model ===
model = build_model()
load_weights_from_txt(model, weights_dir)
model.compile(optimizer='adam', loss='categorical_crossentropy')  # Removed metrics

# === Run inference ===
prediction = model.predict(img_array)
pred_class = np.argmax(prediction[0])

# === Display result ===
plt.imshow(img)
plt.axis('off')
plt.title(f"Predicted: {class_labels[pred_class]}")
plt.show()
