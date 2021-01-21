import iso_numpy
import iso_main
import cv2


image = cv2.imread("/home/meng/Desktop/lbcascade_animeface/lbpcascade_animeface/examples/sample.jpeg", cv2.IMREAD_COLOR)
cascade = cv2.CascadeClassifier("/home/meng/Desktop/lbcascade_animeface/lbpcascade_animeface/lbpcascade_animeface.xml")
# result = cascade.detectMultiScale()


cv2.imshow("aaa",image)
print("12345")
cv2.waitKey(0)
# a = str(1)+"-"+str(1.1)+"-"+str((24, 24))
# m = a.split("-")[2]
# m = eval(m)
# print(type(m))
# a = None
# b = str(a)
# print(type(b))
# m = eval(b)
# print(type(m))
# iso_np_img = iso_numpy.iso_numpy(iso_main.get_free_index(),image)
# iso_main.np2shm(iso_np_img)
# while True:
#     print("aaaaaa")
import iso_numpy
import iso_main
import cv2


img = iso_main.shm2np(0)
cv2.imshow("aaaa",img)
cv2.waitKey(0)