import cv2
import numpy as np

cap = cv2.VideoCapture(0)
facecascade = cv2.CascadeClassifier("Resources/haarcascade_frontalface_default.xml")
# cap.set(3,640)
# cap.set(4,480)
cap.set(10,100) #For brightness
count = 0
while True:
    success, img = cap.read()
    imgGray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces = facecascade.detectMultiScale(imgGray, 1.1, 10)
    for (x, y, w, h) in faces:
        area = w*h
        if area>500:
            cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 255), 2)
            cv2.putText(img,"Face Detected",(x,y-5),cv2.FONT_HERSHEY_SIMPLEX,1,(255,0,255),1)
            imgRoi = img[y:y+h,x:x+w]
            cv2.imshow("Faces", imgRoi)

    cv2.imshow("Result", img)
    if cv2.waitKey(1) == ord('s'):
        cv2.imwrite("Resources/Scanned/Face_"+str(count)+".jpg",imgRoi)
        cv2.rectangle(img,(0,200),(640,300),(0,255,0),cv2.FILLED)
        cv2.putText(img,"Scanned",(150,265),cv2.FONT_HERSHEY_DUPLEX,
                    2,(0,0,255),2)
        cv2.imshow("Result",img)
        cv2.waitKey(500)
        count+=1

        break

