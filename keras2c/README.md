Clone keras2c and set up environment (only once):

```
git clone https://github.com/PlasmaControl/keras2c.git
cd keras2c
pip install -r requirements.txt
cd ..
```

Convert Keras model to C:

```
python convert.py
```

This generates:

```
c_model/my_model.c
c_model/my_model.h
c_model/my_model_test_suite.c
```

Copy keras2c runtime files into c_model:

```
cp -r keras2c/include c_model/
cp -r keras2c/src c_model/
```

Download stb_image header (required for image loading in C):

```
cd c_model
wget https://raw.githubusercontent.com/nothings/stb/master/stb_image.h
cd ..
```

At this point `c_model/` contains:

```
c_model/
  include/
  src/
  stb_image.h
  my_model.c
  my_model.h
  my_model_test_suite.c
```

Build and run generated test suite (sanity check):

```
cd c_model
gcc -O3 my_model.c my_model_test_suite.c include/*.c -I./include -lm -o model_test
./model_test
```

Expected result:
Average time printed, max absolute error ~1e-6.

Run Python prediction on one image (reference output):

```
python predict.py ../sample_images/cat/cat_3.png --preprocess 01
```

Expected result:
Predicted class: cat (3)

Build C predictor:

```
gcc -O3 predict.c my_model.c include/*.c -I./include -lm -o predict
```

Run C prediction on one image:

```
./predict ../sample_images/cat/cat_3.png
```

Expected result:
Same probabilities and predicted class as predict.py.

Run prediction on all images and save results:

```
chmod +x test_all.sh
./test_all.sh
```

Outputs generated:

```
prediction.txt   # full per-image prediction logs
pred_table.txt   # image name | ground truth | predicted class
```

Folder layout reference:

```
c_model/
  include/
  src/
  stb_image.h
  predict.c
  predict
  test_all.sh
  prediction.txt
  pred_table.txt
  my_model.c
  my_model.h
  my_model_test_suite.c
sample_images/
  airplane/
  automobile/
  bird/
  cat/
  deer/
  dog/
  frog/
  horse/
  ship/
  truck/
```

This is the complete setup and execution flow from Keras model to standalone C inference and batch evaluation.
