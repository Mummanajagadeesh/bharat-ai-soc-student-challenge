import numpy as np
import random
import tensorflow as tf
from tensorflow.keras.models import load_model
from tensorflow.keras.datasets import cifar10

# Load full Keras model (.keras)
model = load_model("model.keras")

# Load CIFAR-10 test data
(_, _), (x_test, y_test) = cifar10.load_data()
x_test = x_test.astype("float32") / 255.0

# CIFAR-10 label mapping
label_map = {
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

# Pick 5 random test indices
indices = random.sample(range(len(x_test)), 10)

correct = 0
for idx in indices:
    img = np.expand_dims(x_test[idx], axis=0)  # shape (1, 32, 32, 3)
    pred_probs = model.predict(img, verbose=0)[0]
    pred_class = int(np.argmax(pred_probs))
    true_class = int(y_test[idx][0])

    pred_label = label_map[pred_class]
    true_label = label_map[true_class]

    is_correct = pred_class == true_class
    if is_correct:
        correct += 1

    print(f"Image {idx}: Predicted = {pred_class} ({pred_label}), Actual = {true_class} ({true_label}) {'✅' if is_correct else '❌'}")

print(f"\n🎯 Correct predictions: {correct}/10")
