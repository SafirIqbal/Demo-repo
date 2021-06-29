import cv2
import numpy as np

img = cv2.imread("Faces.jpg")
imgGray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
facecascade = cv2.CascadeClassifier("haarcascade_frontalface_default.xml")
faces = facecascade.detectMultiScale(imgGray,1.1,10)
for (x,y,w,h) in faces:
    cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,255),2)
cv2.imshow("Faces", img)
cv2.waitKey(0)