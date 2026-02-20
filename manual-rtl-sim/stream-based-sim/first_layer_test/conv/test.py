import numpy as np
a=np.loadtxt("../../py-golden/01_conv2d/ch_000.txt",dtype=int)
b=np.loadtxt("conv_res/ch_0.txt",dtype=int)
print("equal?", np.array_equal(a,b))
print("diff min max nonzero:", (a-b).min(), (a-b).max(), ((a-b)!=0).sum())