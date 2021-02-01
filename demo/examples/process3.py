import zmq
import sys
import time
import cv2
import iso_main
import iso_numpy
port = "5558"
context = zmq.Context()
socket = context.socket(zmq.REP)
socket.bind("tcp://*:%s" % port)
while True:
    #  Wait for next request from client
    print("wait for request")
    message = socket.recv()
    func_name = message.decode("utf-8")
    print("process3 get request for "+func_name)
    if(func_name== 'imshow'):
        socket.send_string("args")
        args = socket.recv().decode("utf-8")
        args_list = args.split("-")
        np_src = iso_main.shm2np(int(args_list[1]))
        cv2.imshow(args_list[0],np_src)
        socket.send_string("imshow executed")




    elif(func_name == 'waitkey'):
        socket.send_string("args")
        args = socket.recv().decode("utf-8")
        print(args)
        print(type(args))
        cv2.waitKey(eval(args.split()))
        socket.send_string("waitkey executed")

    elif(func_name == 'imwrite'):
        socket.send_string("args")
        args = socket.recv().decode("utf-8")
        args_list = args.split("-")
        np_src = iso_main.shm2np(int(args_list[1]))
        print(args_list)
        cv2.imwrite(args_list[0],np_src)
        socket.send_string("imwrite executed")      
