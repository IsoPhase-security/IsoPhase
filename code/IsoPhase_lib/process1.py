import zmq
import sys
import time
import cv2
import iso_main
import iso_numpy
from keras.preprocessing import image
import numpy
port = "5556"
context = zmq.Context()
socket = context.socket(zmq.REP)
socket.bind("tcp://*:%s" % port)
i = 0

while True:
    print("wait for request")
    #  Wait for next request from client
    i = i+1
    message = socket.recv()
    func_name = message.decode("utf-8")
    print("process1 get request for "+func_name)
    if(func_name== 'imread'):
        socket.send_string("args")
        args = socket.recv().decode("utf-8")
        arg_list = args.split(",")
        print(arg_list)
        np_img = cv2.imread(arg_list[0],int(arg_list[1]))
        # iso_np = iso_numpy.iso_numpy(iso_main.get_free_index(),np_dst)
        index = iso_main.get_free_index()
        iso_main.np2shm(index ,np_img)
        socket.send_string(str(index))
    elif(func_name == "keras.preprocessing.image.load_img"):
        socket.send_string("args")
        args = socket.recv().decode("utf-8")
        arg_list = args.split("||")
        print(arg_list)
        pil_img = image.load_img(arg_list[0],eval(arg_list[1]),eval(arg_list[2]))
        np_img = numpy.array(pil_img)
        index = iso_main.get_free_index()
        iso_main.np2shm(index,np_img)
        socket.send_string(str(index))

