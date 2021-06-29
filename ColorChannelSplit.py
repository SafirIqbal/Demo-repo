import cv2 as cv
import numpy as np

img = cv.imread("Resources/test.png")

#Splitting the Blue, Green and Red Channels#
blank = np.zeros(img.shape[:2], np.uint8)

b,g,r = cv.split(img)

#Showing splitted colors/channels#

blue = cv.merge([b,blank,blank])
green = cv.merge([blank,g,blank])
red = cv.merge([blank,blank,r])


merged = cv.merge([b,g,r])
cv.imshow("Result1", b)
cv.imshow("Result2", g)
cv.imshow("Result3", r)
cv.imshow("Merged", merged)
cv.imshow("Blank", blank)
cv.imshow("Blue", blue)
cv.imshow("Green", green)
cv.imshow("Red", red)

cv.waitKey(0)