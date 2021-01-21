# import iso_main
# from iso_keras.models import load_model
# from iso_keras.preprocessing import image
from keras.preprocessing import image
# a1 = load_model("/home/meng/Desktop/face_classification/trained_models/fer2013_big_XCEPTION.54-0.66.hdf5",compile=False)
# shape = a1.inputshape[1:3]
# print(shape)
# a = image.load_img("/home/meng/Desktop/face_classification/images/test_image.jpg")
# print(type(a))
img = image.load_img("/home/meng/Desktop/face_classification/images/test_image.jpg",grayscale=False)
tmp = image.img_to_array(img)
class np_arr:
    def __init__(self):
        self.arr = tmp
        self.type = "np"
    def __getitem__(self,index):
        print(index)
        print(type(index))
        return self.arr[index]
tmp_arr = np_arr()

print(tmp_arr[1:3,2:4]) 