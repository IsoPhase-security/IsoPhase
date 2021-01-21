import numpy
import iso_main
import SharedArray
class iso_numpy():
    def __init__(self, index, np_array):
        self.index = index
        print("index: "+str(self.index)+" is assigned")
        self.np_array = np_array

    def __del__(self):
        iso_main.free_index("phase1",self.index)
        print("iso_numpy: "+str(self.index)+" destructor called")

    def __getitem__(self, val):
        np_arr = self.np_array
        print("index: "+str(self.index)+" getitem called")
        return np_arr[val]

    def __contains__(self,a):
        print("in is called")
        return self.np_array.__contains__(a)
    

def zeros(shape, dtype=float, order='C'):
    ndarray = numpy.zeros(shape,dtype,order)
    iso_array = iso_numpy(2,ndarray)
    return iso_array