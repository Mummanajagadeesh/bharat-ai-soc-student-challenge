#!/usr/bin/env python3
import argparse
import numpy as np
from PIL import Image
from tensorflow.keras.models import load_model

CLASSES = [
    "airplane","automobile","bird","cat","deer",
    "dog","frog","horse","ship","truck"
]

def load_and_preprocess(img_path, mode):
    img = Image.open(img_path).convert("RGB").resize((32, 32))
    x = np.array(img).astype(np.float32)

    if mode == "01":
        x = x / 255.0

    elif mode == "m11":
        x = (x / 255.0 - 0.5) * 2.0

    elif mode == "cifar":
        mean = np.array([0.4914, 0.4822, 0.4465], dtype=np.float32)
        std  = np.array([0.2470, 0.2435, 0.2616], dtype=np.float32)
        x = x / 255.0
        x = (x - mean) / std

    else:
        raise ValueError("Unknown preprocess mode")

    return x

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("image", help="path to image")
    ap.add_argument(
        "--preprocess",
        choices=["01", "m11", "cifar"],
        default="01",
        help="01 = /255, m11 = [-1,1], cifar = mean/std"
    )
    ap.add_argument(
        "--model",
        default="../model.keras",
        help="path to keras model"
    )
    args = ap.parse_args()

    model = load_model(args.model)

    x = load_and_preprocess(args.image, args.preprocess)
    preds = model.predict(x[None, ...], verbose=0)[0]

    best = int(np.argmax(preds))

    print("\nPrediction:")
    for i, p in enumerate(preds):
        print(f"{CLASSES[i]:12s}: {p:.6f}")

    print(f"\nPredicted class: {CLASSES[best]} ({best})")

if __name__ == "__main__":
    main()
