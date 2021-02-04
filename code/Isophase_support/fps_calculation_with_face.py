import cv2
import imutils
import time
import copy
from imutils.video import FPS
from picamera import PiCamera
from picamera.array import PiRGBArray
from threading import Thread

#cam = cv2.VideoCapture(0)
#cam.set(3,640)
#cam.set(4,480)
#cv2.namedWindow("test")
faceCascade = cv2.CascadeClassifier('frontalface.xml')
#fakeCascade = cv2.CascadeClassifier()

class PiVideoStream:
    def __init__(self, resolution=(640, 480), framerate=32):
        self.camera = PiCamera()
        self.camera.resolution = resolution
        self.camera.framerate = framerate
        self.rawCapture = PiRGBArray(self.camera, size = resolution) #output file object
        self.stream = self.camera.capture_continuous(self.rawCapture, 
                format='bgr', use_video_port=True)

        self.frame = None
        self.stopped = False

    def start(self):
        Thread(target=self.update, args=()).start()
        return self
    
    def update(self):
        for f in self.stream:
            self.frame = f.array
            self.rawCapture.truncate(0) #rawCamer must be cleared every iteration
            faces = faceCascade.detectMultiScale(
                    frame,
                    scaleFactor=1.2,
                    minNeighbors=5,
                    minSize=(20,20))
            for (x,y,w,h) in faces: 
                cv2.rectangle(frame, (x,y), (x+w,y+h), (255,127,90),2)

            if self.stopped:
                self.stream.close()
                self.rawCapture.close()
                self.camera.close()
                return
    def read(self):
        return self.frame
    def stop(self):
        self.stopped = True

#flag to display images
display = True
num_frames = 200 # number of frames to capture
show_naive = False # not used
cv2.setUseOptimized(False) # change flag to enable SIMD optimization


#non-threaded
camera = PiCamera()
camera.resolution = (640,480)
camera.framerate = 32
rawCapture = PiRGBArray(camera, size=(640,480))
stream = camera.capture_continuous(rawCapture, format='bgr', #rawCapture is the output
        use_video_port=True)
time.sleep(2.0)
fps = FPS().start()
for (i, f) in enumerate(stream):
    frame = f.array
    #frame = imutils.resize(frame, width=400)
    rawCapture.truncate(0)

    faces = faceCascade.detectMultiScale(
            frame,
            scaleFactor=1.2,
            minNeighbors=5,
            minSize = (20,20)
            )
    #print("size of faces: ", len(faces))
    for (x,y,w,h) in faces:
        cv2.rectangle(frame, (x,y), (x+w,y+h), (255,255,0), 2)

    if display:
        cv2.imshow("Frame", frame)
        key = cv2.waitKey(1) & 0xFF

    fps.update()
    #print("num frames:",fps._numFrames)
    if (fps._numFrames > num_frames):
        #if (i > num_frames):
        break
fps.stop()
print("non-threaded with face detection")
print("elapsed time:", fps.elapsed())
print("approx. fps:", fps.fps())

cv2.destroyAllWindows()
stream.close()
rawCapture.close()
camera.close()

#THREADED
vs = PiVideoStream().start()
time.sleep(2.0)
fps = FPS().start()

while (fps._numFrames < num_frames):
    frame = vs.read()
    if display:
        cv2.imshow("Threaded", frame)
        cv2.waitKey(1) & 0xFF

    fps.update()
fps.stop()
print("threaded with face detection")
print("elapsed time:", fps.elapsed())
print("approx. fps:", fps.fps())

cv2.destroyAllWindows()
vs.stop()
