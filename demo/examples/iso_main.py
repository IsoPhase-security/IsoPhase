#from multiprocessing import shared_memory
import iso_numpy
import numpy
import SharedArray as sa
import cv2
import zmq

img_size = 1280*720*3

shm_size = 1280*720*3*100
try:
    shm = sa.create("phase1", shm_size)
except:
    print("it exist, so we just attach")
    shm = sa.attach("phase1")

index_table = shm[0:100]#the beginning of index table
record_table = shm[100:500]#the beginning of recotd table
data = shm[500:-1]#beginning address of the real data part

port2 = "5557"
context2 = zmq.Context()
print("Connecting to server...")
socket2 = context2.socket(zmq.REQ)
socket2.connect ("tcp://localhost:%s" % port2)


class iso_object:
    def __init__(self,index,name = "np"):
        self.type = name
        self.index = index
    def __getitem__(self,index):
        np_src = shm2np(self.index)
        np_dst = np_src[index]
        index = get_free_index()
        np2shm(index,np_dst)
        return iso_object(index)

class iso_model:
    def __init__(self,index,name = "pytorch"):
        self.type = name
        self.index = index
        self.inputshape = self.getinputshape()
    def getinputshape(self):
        if(self.type == "keras"):
            socket2.send_string("keras.model.inputshape")
            message = socket2.recv()
            arg_string = str(self.index)
            socket2.send_string(arg_string)
            message = socket2.recv().decode("utf-8")
            return eval(message)


def shm2np(index):
    offset = index*img_size
    table_offset = (index)*4

    shape = record_table[table_offset:table_offset+4]
    length = shape[3]
    flat_arr = data[offset:offset+int(length)]
    np_array = numpy.reshape(flat_arr,shape[0:3].astype(numpy.int))
    tmp_img = cv2.convertScaleAbs(np_array)
    return tmp_img

# @overload
# def np2shm(iso_numpy):
#     index = iso_numpy.index

#     np_array = iso_numpy.np_array
#     print(np_array.shape)
#     if(len(np_array.shape)==3):
#         width,height,dim = np_array.shape
#     else:
#         width,height = np_array.shape
#         dim = 1

#     length = width*height*dim
#     flat_arr = np_array.flatten()
#     offset = (index)*img_size
#     data[offset:offset+length] = flat_arr[0:length]
#     table_offset = index*4
#     record_table[table_offset] = width
#     record_table[table_offset+1] = height
#     record_table[table_offset+2] = dim
#     record_table[table_offset+3] = length
    
# @np2shm.overload
def np2shm(index,np_array):
    print(np_array.shape)
    if(len(np_array.shape)==3):
        width,height,dim = np_array.shape
    else:
        width,height = np_array.shape
        dim = 1

    length = width*height*dim
    flat_arr = np_array.flatten()
    offset = (index)*img_size
    data[offset:offset+length] = flat_arr[0:length]
    table_offset = index*4
    record_table[table_offset] = width
    record_table[table_offset+1] = height
    record_table[table_offset+2] = dim
    record_table[table_offset+3] = length


def get_free_index():
    k = 0
    index_table = shm[0:100]
    while(k < 100):
        if(index_table[k]==0):
            index_table[k]=1
            print("index: "+str(k)+" found")
            return k
        k = k + 1
    print("cannot find free index")
    return -1


def free_index(shm_name,index):
    shm = sa.attach(shm_name)
    shm[index] = 0 











# class shmem_record():
#     def __init__(self,width,height,dimension):
#         self.width = width
#         self.height = height
#         self.dimension = dimension
#         self.length = width*height*dimension




# class shm_phase():
#     def __init__(self,shm_name):
#         self.name = shm_name #name of the shared memory
#         self.size = 1280*720*3*100 #default size of shared memory
#         self.shm = sa.create(shm_name, self.size) #shared memory object
#         self.phase = 0 # represent the which phase this shared memory is for
#         self.connect_status = True #True if shared meem is connected
        
#         self.index_table = self.shm[0:100]#the beginning of index table
#         self.record_table = self.shm[100:500]#the beginning of recotd table
#         self.data = self.shm[500:-1]#beginning address of the real data part


#     def create(self,shm_name):
#         if(self.connect_status is False):
#             self.shm = sa.create(shm_name, size=self.size)
#             self.connect_status = True
#             self.name = shm_name
#         else:
#             print("shared memory has been created")

#     def connect(self):
#         if(self.connect_status is True):
#             return self.shm
#         else:
#             self.shm = sa.attach(self.name)
#             self.connect_status = True
#             return self.shm
    
#     def disconnect(self):
#         # self.index_table.release()
#         # self.record_table.release()
#         # self.data.release()
#         # self.shm.close()
#         # self.shm.unlink()
#         self.connect_status = False

#     def np2shm(self,iso_numpy):

#         index = iso_numpy.index

#         np_array = iso_numpy.np_array
#         print(type(np_array))
#         width,height,dim = np_array.shape
#         length = width*height*dim
#         flat_arr = np_array.flatten()

#         offset = (index)*img_size
#         self.data[offset:offset+length] = flat_arr[0:length]

#         table_offset = index*4
#         self.record_table[table_offset] = width
#         self.record_table[table_offset+1] = height
#         self.record_table[table_offset+2] = dim
#         self.record_table[table_offset+3] = length
#         print("np2shm")
#         print(self.record_table[0:4])
        
#     def shm2np(self,index):
#         offset = index*img_size
#         table_offset = (index)*4
#         print("shm2np")
#         print(self.record_table[0:4])
#         shape = self.record_table[table_offset:table_offset+4]
#         print(shape)
#         length = shape[3]

#         flat_arr = self.data[offset:offset+int(length)]
#         np_array = numpy.reshape(flat_arr,shape[0:3].astype(numpy.int))
#         print("aaaaaa")
#         print(len(np_array))
#         tmp_img = cv2.convertScaleAbs(np_array)
#         return tmp_img

#     def get_free_index(self):
#         k = 0
#         while(k < 100):
#             if(self.index_table[k]==0):
#                 self.index_table[k]=1
#                 return k
#             k = k + 1
#         print("cannot find free index")
#         return -1
    
#     def free_index(self,index):
#         self.index_table[index]=0
    
#     def __del__(self):
#         sa.delete(self.name)
#         self.disconnect()


