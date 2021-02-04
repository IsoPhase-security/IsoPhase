import os, sys
currentdir = os.path.dirname(os.path.realpath(__file__))
parentdir = os.path.dirname(currentdir)
sys.path.append(parentdir)
import zmq
import iso_main
import iso_numpy
# port1 = "5556"
# context1 = zmq.Context()
# print("Connecting to server...")
# socket1 = context1.socket(zmq.REQ)
# socket1.connect ("tcp://localhost:%s" % port1)

port2 = "5557"
context2 = zmq.Context()
print("Connecting to server...")
socket2 = context2.socket(zmq.REQ)
socket2.connect ("tcp://localhost:%s" % port2)

# port3 = "5558"
# context3 = zmq.Context()
# print("Connecting to server...")
# socket3 = context3.socket(zmq.REQ)
# socket3.connect ("tcp://localhost:%s" % port3)

def load_model(filepath, custom_objects=None, compile=True):
    socket2.send_string("keras.models.load_model")
    message = socket2.recv()
    arg_string = str(filepath)+"||"+str(custom_objects)+"||"+str(compile)
    socket2.send_string(arg_string)
    message = socket2.recv().decode("utf-8")
    return iso_main.iso_model(int(message),"keras")

