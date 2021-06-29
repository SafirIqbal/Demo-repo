import cv2
import numpy as np

cap = cv2.VideoCapture(0)
myColor = [[53,109,165,123,255,255],[133,56,0,159,156,255]] #MyBluePen
myReqColor = [[255,0,0],[255,0,255]] #BGR
'''Written as hmin,smin,vmin and hmax,smax,vmax so that It is easy to write
in lower and upper'''
myPoints = [] #[x,y,color[0]]

def findColor(img):
    imgHSV = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
    newPoints = []
    count=0
    for color in myColor:
        lower = np.array(color[0:3])
        upper = np.array(color[3:6])
        mask = cv2.inRange(imgHSV,lower,upper)
        # cv2.imshow("Mask", mask)
        x,y = getContours(mask)
        cv2.circle(imgResult, (x, y), 10, myReqColor[count], cv2.FILLED)

        if x!=0 and y!=0:
                newPoints.append([x,y,count])
        count+=1
    return newPoints

def getContours(img):
    contours,hierarchy = cv2.findContours(img,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
    x,y,w,h = 0,0,0,0
    for cnt in contours:
        area = cv2.contourArea(cnt)
        if area>500:
            cv2.drawContours(imgResult,cnt,-1,(255,0,0),3)
            peri = cv2.arcLength(cnt,True)
            approx = cv2.approxPolyDP(cnt,0.02*peri,True)
            x,y,w,h = cv2.boundingRect(approx)
    return x+w//2,y

def drawonCanvas(myPoints,myReqColor):
    for point in myPoints:
        cv2.circle(imgResult,(point[0],point[1]),10,myReqColor[point[2]],cv2.FILLED)

while True:
    success, img = cap.read()
    imgResult = img.copy()
    newPoints = findColor(img)
    if len(newPoints)!=0:
        for newP in newPoints:
            myPoints.append(newP)
    if len(myPoints)!=0:
        drawonCanvas(myPoints,myReqColor)
    cv2.imshow("Webcam", imgResult)
    if cv2.waitKey(1)==ord('q'):
        break