jimport cv2
import iso_numpy

IMREAD_COLOR = cv2.IMREAD_COLOR
COLOR_BGR2GRAY = cv2.COLOR_BGR2GRAY
class CascadeClassifier():
    def __init__(self, cascade_file, index = -1):#phase 2
        self.cascadeclassifier = cv2.CascadeClassifier(cascade_file)
        self.index = index
    def detectMultiScale(self,iso_img,scaleFactor = 1.1,minNeighbors = 5,minSize = (24, 24)):#phase 2
        img = iso_img.np_array
        out_mat = self.cascadeclassifier.detectMultiScale(img,scaleFactor = 1.1,minNeighbors = 5,minSize = (24, 24))
        iso_out = iso_numpy.iso_numpy(4,out_mat)
        return iso_out

def cvtColor(iso_img,code):#phase 2
    img = iso_img.np_array
    out_mat = cv2.cvtColor(img,code)
    iso_out = iso_numpy.iso_numpy(2,out_mat)
    return iso_out

def equalizeHist(iso_img):#phase 2
    img = iso_img.np_array
    out_mat = cv2.equalizeHist(img)
    iso_out = iso_numpy.iso_numpy(3,out_mat)
    return iso_out

def imread(filename:str,code):#phase 1
    img = cv2.imread(filename,code)
    iso_img = iso_numpy.iso_numpy(1,img)
    return iso_img

def rectangle(iso_img,start_point, end_point, color, thickness):#phase 2
    img = iso_img.np_array
    cv2.rectangle(img,start_point, end_point, color, thickness)

def imshow(name,iso_img):#phase 3
    print(iso_img.index)
    img = iso_img.np_array
    cv2.imshow(name,img)

def waitKey(input):#phase 3
    cv2.waitKey(input)

def imwrite(filename,iso_img):#phase 3
    img = iso_img.np_array
    cv2.imwrite(filename,img)

