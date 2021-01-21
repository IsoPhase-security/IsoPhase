import zmq
import sys
import time
import cv2
import iso_main
import iso_numpy
port = "5557"
context = zmq.Context()
socket = context.socket(zmq.REP)
socket.bind("tcp://*:%s" % port)

i = 0

while True:
    #  Wait for next request from client
    i = i+1
    print("wait for request")
    message = socket.recv()
    func_name = message.decode("utf-8")
    print("process2 get request for "+func_name)
    if(func_name== 'CascadeClassifier'):
        socket.send_string("args")
        args = socket.recv().decode("utf-8")
        args_list = args.split(",")
        cascade = cv2.CascadeClassifier(args_list[0])
        socket.send_string("classifier created in phase2")

    elif(func_name == "detectMultiScale"):
        socket.send_string("args")
        args = socket.recv().decode("utf-8")
        args_list = args.split("-")
        print(args_list)
        np_src = iso_main.shm2np(int(args_list[0]))
        np_dst = cascade.detectMultiScale(np_src,eval(args_list[1]),eval(args_list[2]),eval(args_list[3]),eval(args_list[4]),eval(args_list[5]))
        iso_np = iso_numpy.iso_numpy(iso_main.get_free_index(),np_dst)
        iso_main.np2shm(iso_np)
        socket.send_string(str(iso_np.index))



    elif(func_name == "cvtColor"):
        socket.send_string("args")
        args = socket.recv().decode("utf-8")
        args_list = args.split(",")
        np_src = iso_main.shm2np(int(args_list[0]))
        # print(args_list)
        # print("inside process2 cvtColor")
        # print(type(np_src))
        np_dst = cv2.cvtColor(np_src,int(args_list[1]))
        iso_np = iso_numpy.iso_numpy(iso_main.get_free_index(),np_dst)
        iso_main.np2shm(iso_np)
        socket.send_string(str(iso_np.index))

    elif(func_name == "equalizeHist"):
        socket.send_string("args")
        args = socket.recv().decode("utf-8")
        np_src = iso_main.shm2np(int(args[0]))
        np_dst = cv2.equalizeHist(np_src)
        iso_np = iso_numpy.iso_numpy(iso_main.get_free_index(),np_dst)
        iso_main.np2shm(iso_np)
        socket.send_string(str(iso_np.index))
