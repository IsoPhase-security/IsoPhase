import zmq
import sys
import cv2
port = "5556"
context = zmq.Context()
print("Connecting to server...")
socket = context.socket(zmq.REQ)
socket.connect ("tcp://localhost:%s" % port)

socket.send_string("imread")
#  Get the reply.
message = socket.recv()
print(message.decode("utf-8"))
if(message.decode("utf-8") == 'args'):
    str1=""
    arg1 = "sample.jpeg"
    arg2 = str(cv2.IMREAD_COLOR)
    args = arg1+","+arg2
    print(args)
    socket.send_string(args)
    print("args sent")
    message = socket.recv().decode("utf-8")
    print(message)