import os
import numpy as np
import tensorflow as tf
from tensorflow.keras import layers, models
from tensorflow.keras.datasets import cifar10
import matplotlib.pyplot as plt

# === CONFIG ===
weights_dir = "weights_txt"

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

# === Rebuild model architecture (must match training) ===
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

        # BatchNorm layers: 4 params
        if isinstance(layer, tf.keras.layers.BatchNormalization):
            for kind in ["gamma", "beta", "moving_mean", "moving_variance"]:
                shape_file = os.path.join(weights_dir, f"layer_{i}_{kind}_shape.txt")
                data_file = os.path.join(weights_dir, f"layer_{i}_{kind}.txt")

                with open(shape_file, "r") as f:
                    shape = tuple(map(int, f.read().split()))
                arr = np.loadtxt(data_file).reshape(shape)
                weights.append(arr)

        # Conv2D / Dense: kernel + bias
        elif isinstance(layer, (tf.keras.layers.Conv2D, tf.keras.layers.Dense)):
            for kind in ["kernel", "bias"]:
                shape_file = os.path.join(weights_dir, f"layer_{i}_{kind}_shape.txt")
                data_file = os.path.join(weights_dir, f"layer_{i}_{kind}.txt")

                with open(shape_file, "r") as f:
                    shape = tuple(map(int, f.read().split()))
                arr = np.loadtxt(data_file).reshape(shape)
                weights.append(arr)

        # Set weights if applicable
        if weights:
            layer.set_weights(weights)

# === Load test images from CIFAR-10 ===
(_, _), (x_test, y_test) = cifar10.load_data()
x_test = x_test.astype("float32") / 255.0

# Pick 5 random samples
indices = np.random.choice(len(x_test), 5, replace=False)
sample_images = x_test[indices]
sample_labels = y_test[indices]

# === Build and load model ===
model = build_model()
load_weights_from_txt(model, weights_dir)
model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])

# === Run inference ===
predictions = model.predict(sample_images)

# === Display results ===
for i in range(5):
    plt.imshow(sample_images[i])
    plt.axis('off')
    pred_class = np.argmax(predictions[i])
    true_class = sample_labels[i][0]
    plt.title(f"Pred: {class_labels[pred_class]}\nTrue: {class_labels[true_class]}")
    plt.show()