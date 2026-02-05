# convert.py
import os
from tensorflow.keras.models import load_model
from keras2c import k2c

# Load your trained model file (h5 or keras)
model = load_model("model.keras")   # change filename if needed

# Optionally create an output folder and switch into it
os.makedirs("c_model", exist_ok=True)
cwd = os.getcwd()
os.chdir("c_model")

# Call k2c: second arg is the function name (positional), not `name=`
k2c(model, "my_model", malloc=False, num_tests=10, verbose=True)

# restore cwd (optional)
os.chdir(cwd)
