from keras.preprocessing import image
import numpy as np
import os, sys
currentdir = os.path.dirname(os.path.realpath(__file__))
parentdir = os.path.dirname(currentdir)
sys.path.append(parentdir)
import zmq
import iso_main
import iso_numpy
port1 = "5556"
context1 = zmq.Context()
print("Connecting to server...")
socket1 = context1.socket(zmq.REQ)
socket1.connect ("tcp://localhost:%s" % port1)

def load_img(path, grayscale=False,target_size=None):
    socket1.send_string("keras.preprocessing.image.load_img")
    message = socket1.recv()
    arg_string = str(path)+"||"+str(grayscale)+"||"+str(target_size)
    socket1.send_string(arg_string)
    message = socket1.recv().decode("utf-8")
    return iso_main.iso_object(int(message))
