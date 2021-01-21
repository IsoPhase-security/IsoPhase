from cv2 import *
import torch.nn as nn
import numpy as np,torch as tc
import matplotlib
from torch.autograd import Variable as v
def foo_func(node1,node2):
    print("imaaaa")
    m =4
    return 4
    return m

def main():
    img = imread("Sample.jpg")
    a = 4
    b=4
    c = foo_func(a,b)
    imshow("a",img)
    waitKey()

main()