import zmq
import sys
import time
import cv2
port = "5556"
context = zmq.Context()
socket = context.socket(zmq.REP)
socket.bind("tcp://*:%s" % port)
i = 0
while True:
    #  Wait for next request from client
    i = i+1
    message = socket.recv()
    func_name = message.decode("utf-8")
    if(func_name== 'imread'):
        socket.send_string("args")
        args = socket.recv().decode("utf-8")
        print(args)
        print(type(args))
        arg_list = args.split(",")
        print(arg_list)
    socket.send_string(func_name + " executed")