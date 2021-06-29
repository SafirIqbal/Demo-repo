import numpy as np
import cv2 as cv

img = cv.imread("Resources/test.png")
gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
cv.imshow("Gray", gray)
lap = cv.Laplacian(gray,cv.CV_64F)
lap = np.uint8(np.absolute(lap))
cv.imshow("Laplacian", lap)

cv.waitKey(0)