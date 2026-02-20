import tensorflow as tf
import numpy as np
import os
import shutil
from PIL import Image
import random

# Config
output_dir = 'sample_images'
images_per_class = 10
random_seed = None  # Set an integer for reproducibility, or None for new random every time

def reset_output_dir():
    if os.path.exists(output_dir):
        shutil.rmtree(output_dir)
    os.makedirs(output_dir)

def save_images(x, y, class_names):
    if random_seed is not None:
        random.seed(random_seed)
        np.random.seed(random_seed)

    class_to_indices = {i: np.where(y == i)[0] for i in range(10)}

    for class_idx in range(10):
        indices = class_to_indices[class_idx]
        chosen_indices = np.random.choice(indices, images_per_class, replace=False)
        class_name = class_names[class_idx]
        class_dir = os.path.join(output_dir, class_name)
        os.makedirs(class_dir, exist_ok=True)

        for i, img_idx in enumerate(chosen_indices):
            img_array = x[img_idx]
            img = Image.fromarray(img_array)
            img.save(os.path.join(class_dir, f"{class_name}_{i}.png"))

def main():
    print("Loading CIFAR-10 dataset...")
    (x_train, y_train), _ = tf.keras.datasets.cifar10.load_data()
    x_train = x_train.astype('uint8')
    y_train = y_train.flatten()
    class_names = [
        'airplane', 'automobile', 'bird', 'cat', 'deer',
        'dog', 'frog', 'horse', 'ship', 'truck'
    ]

    reset_output_dir()
    save_images(x_train, y_train, class_names)
    print(f"Images saved in '{output_dir}'.")

if __name__ == '__main__':
    main()
