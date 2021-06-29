import cv2
import numpy as np

cap = cv2.VideoCapture(0)

def empty(a):
    pass

cv2.namedWindow("Trackbars")
cv2.createTrackbar("Hue Min","Trackbars",0,179,empty)
cv2.createTrackbar("Hue Max","Trackbars",179,179,empty)
cv2.createTrackbar("Sat Min","Trackbars",0,255,empty)
cv2.createTrackbar("Sat Max","Trackbars",255,255,empty)
cv2.createTrackbar("Val Min","Trackbars",0,255,empty)
cv2.createTrackbar("Val Max","Trackbars",255,255,empty)

while True:
    success, img = cap.read()
    imgHSV = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
    hmin = cv2.getTrackbarPos("Hue Min","Trackbars")
    hmax = cv2.getTrackbarPos("Hue Max","Trackbars")
    smin = cv2.getTrackbarPos("Sat Min","Trackbars")
    smax = cv2.getTrackbarPos("Sat Max","Trackbars")
    vmin = cv2.getTrackbarPos("Val Min","Trackbars")
    vmax = cv2.getTrackbarPos("Val Max","Trackbars")
    print(hmin,hmax,smin,smax,vmin,vmax)
    lower = np.array([hmin,smin,vmin])
    upper = np.array([hmax,smax,vmax])
    mask = cv2.inRange(imgHSV,lower,upper)
    result = cv2.bitwise_and(img,img,mask=mask)
    mask = cv2.cvtColor(mask,cv2.COLOR_GRAY2BGR)
    hstack = np.hstack([img,mask,result])
    cv2.imshow("Stacked",hstack)
    if cv2.waitKey(1)==ord('q'):
        break



#Blue Pen: 53 123 109 255 165 255#