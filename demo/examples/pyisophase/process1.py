import zmq
import sys
import time
import cv2
import iso_main
import iso_numpy
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
        iso_np_img = iso_numpy.iso_numpy(iso_main.get_free_index(),np_img)
        #print(type(iso_np_img))
        iso_main.np2shm(iso_np_img)
        socket.send_string(str(iso_np_img.index))