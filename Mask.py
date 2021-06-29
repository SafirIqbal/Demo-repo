import cv2 as cv
import numpy as np

img = cv.imread("Resources/opencv-course/Resources/Photos/cats 2.jpg")
blank = np.zeros(img.shape[:2],np.uint8)

mask = cv.rectangle(blank,(blank.shape[1]//2-150,blank.shape[0]//2-150),(blank.shape[1]//2 + 150,blank.shape[0]//2 + 150),255,cv.FILLED)
bitwiseand = cv.bitwise_and(img,img,mask=mask)
cv.imshow("Blank", blank)
cv.imshow("Cats", img)
cv.imshow("Mask", mask)
cv.imshow("And", bitwiseand)
cv.waitKey(0)
