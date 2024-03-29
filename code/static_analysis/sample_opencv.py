import cv2
import numpy as np
from matplotlib import pyplot as plt
import torch.nn as nn
import torch.nn.functional as F
import torch
from torch.autograd import Variable1, Variable2

class TwoLayerNet(nn.Module):
    def __init__(self, D_in, H, D_out):
        """
        In the constructor we instantiate two nn.Linear modules and assign them as
        member variables.

        D_in: input dimension
        H: dimension of hidden layer
        D_out: output dimension
        """
        super(TwoLayerNet, self).__init__()
        self.linear1 = nn.Linear(D_in, H) 
        self.linear2 = nn.Linear(H, D_out)

def forward(self, x):
        """
        In the forward function we accept a Variable of input data and we must 
        return a Variable of output data. We can use Modules defined in the 
        constructor as well as arbitrary operators on Variables.
        """
        h_relu = F.relu(self.linear1(x))
        y_pred = self.linear2(h_relu)
        return y_pred

img = cv2.imread('sample.jpg')
print(type(img))
print(img.shape)
img = cv2.resize(img,None,fx=0.5,fy=0.5)
cv2.imshow('image',img)
cv2.waitKey(0)
cv2.destroyAllWindows()

N, D_in, H, D_out = 32, 100, 50, 10
x = Variable(torch.randn(N, D_in))
model = TwoLayerNet(D_in, H, D_out)
y_pred = model(x)
