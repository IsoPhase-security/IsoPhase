import cv2
import iso_numpy
import iso_main
import zmq

IMREAD_COLOR = cv2.IMREAD_COLOR
COLOR_BGR2GRAY = cv2.COLOR_BGR2GRAY
FONT_HERSHEY_SIMPLEX = cv2.FONT_HERSHEY_SIMPLEX

port1 = "5556"
context1 = zmq.Context()
print("Connecting to server...")
socket1 = context1.socket(zmq.REQ)
socket1.connect ("tcp://localhost:%s" % port1)

port2 = "5557"
context2 = zmq.Context()
print("Connecting to server...")
socket2 = context2.socket(zmq.REQ)
socket2.connect ("tcp://localhost:%s" % port2)

port3 = "5558"
context3 = zmq.Context()
print("Connecting to server...")
socket3 = context3.socket(zmq.REQ)
socket3.connect ("tcp://localhost:%s" % port3)


class CascadeClassifier():
    def __init__(self, cascade_file):#phase 2
        socket2.send_string("CascadeClassifier")
        message = socket2.recv()
        print(message)
        arg_string = str(cascade_file)
        socket2.send_string(arg_string)
        message = socket2.recv().decode("utf-8")
        print(message)

    def detectMultiScale(self,iso_obj, scaleFactor=None, minNeighbors=None, flags=None, minSize=None, maxSize=None):#phase 2
        index = iso_obj.index
        socket2.send_string("detectMultiScale")
        message = socket2.recv()
        arg_string = str(index)+"-"+str(scaleFactor)+"-"+str(minNeighbors)+"-"+str(flags)+"-"+str(minSize)+"-"+str(maxSize)
        socket2.send_string(arg_string)
        message = socket2.recv().decode("utf-8")
        np_arr = iso_main.shm2np(int(message))
        np_arr = np_arr.astype("int32")
        return np_arr


def cvtColor(iso_obj,code):#phase 2
    index = iso_obj.index
    socket2.send_string("cvtColor")
    message = socket2.recv()
    #print("socket2: "+message)
    arg_string = str(index)+","+str(code)
    socket2.send_string(arg_string)
    message = socket2.recv().decode("utf-8")
    return iso_main.iso_object(int(message))

def equalizeHist(iso_obj):#phase 2
    index = iso_obj.index
    socket2.send_string("equalizeHist")
    message = socket2.recv()
    #print(message)
    arg_string = str(index)
    socket2.send_string(arg_string)
    message = socket2.recv().decode("utf-8")
    return iso_main.iso_object(int(message))

def imread(filename:str,code):#phase 1
    socket1.send_string("imread")
    message = socket1.recv()
    arg_string = str(filename)+","+str(code)
    socket1.send_string(arg_string)
    message = socket1.recv().decode("utf-8")
    return iso_main.iso_object(int(message))
    # img = cv2.imread(filename,code)
    # iso_img = iso_numpy.iso_numpy(1,img)
    # return iso_img

def rectangle(iso_obj,start_point, end_point, color, thickness):#phase 2
    index = iso_obj.index
    socket3.send_string("rectangle")
    message = socket3.recv()
    arg_string = str(index)+"-"+str(start_point)+"-"+str(end_point)+"-"+str(color)+"-"+str(thickness)
    print("rectangle: "+arg_string)
    socket3.send_string(arg_string)
    message = socket3.recv()
    print(message)


def imshow(name,iso_obj):#phase 3
    index = iso_obj.index
    socket3.send_string("imshow")
    message = socket3.recv()
    arg_string = str(name)+"-"+str(index)
    socket3.send_string(arg_string)
    message = socket3.recv()
    print(message)

def waitKey(input):#phase 3
    socket3.send_string("waitKey")
    message = socket3.recv()
    arg_string = str(input)
    socket3.send_string(arg_string)
    message = socket3.recv()
    print(message)


def imwrite(filename,iso_obj):#phase 3
    index = iso_obj.index
    socket3.send_string("imwrite")
    message = socket3.recv()
    arg_string = str(filename)+"-"+str(index)
    socket3.send_string(arg_string)
    message = socket3.recv().decode("utf-8")
    print(message)


