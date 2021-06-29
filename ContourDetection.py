import cv2
import numpy as np

def getContours(img):
    contours,hierarchy = cv2.findContours(img,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
    for cnt in contours:
        area = cv2.contourArea(cnt)
        print(area)
        if area>500:
            cv2.drawContours(imgContour,cnt,-1,(255,0,255),3)
            peri = cv2.arcLength(cnt,True)
            print(peri)
            approx = cv2.approxPolyDP(cnt,0.02*peri,True)
            print(approx)
            print(len(approx))
            objCorner = len(approx)
            x,y,w,h = cv2.boundingRect(approx)
            if objCorner==3:objType = 'Tri'
            elif objCorner==4:
                aspRatio = w/float(h)
                if aspRatio>0.95 and aspRatio<1.05:
                    objType='Square'
                else:objType='Rect'
            elif objCorner>4:
                objType='Circle'



            cv2.rectangle(imgContour,(x,y),(x+w,y+h),(255,0,230),3)
            cv2.putText(imgContour,objType,(x+(w//2)-10,y),cv2.FONT_HERSHEY_PLAIN,1.5,(0,0,255),2)


img = cv2.imread("shapes.png")
imgGray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
imgBlur = cv2.GaussianBlur(imgGray,(3,3),1)
imgCanny = cv2.Canny(imgBlur,25,50)
kernel = np.ones((2,2),np.uint8)
imgDilate = cv2.dilate(imgCanny,kernel,iterations=1)
imgContour = img.copy()
getContours(imgDilate)
# cv2.imshow("Image", img)
# cv2.imshow("Image Gray", imgGray)
# cv2.imshow("Image Blur", imgBlur)
# cv2.imshow("Image Canny", imgCanny)

cv2.imshow("Image Contour", imgContour)
# cv2.imshow("Image Dilate", imgDilate)

cv2.waitKey(0)