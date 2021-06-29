import matplotlib
import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

img = cv.imread("Resources/opencv-course/Resources/Photos/cat.jpg")
# #BGR to LAB

imgLAB = cv.cvtColor(img,cv.COLOR_BGR2Lab)

cv.imshow("Result", img)
plt.imshow(img)
plt.show()
cv.waitKey(0)


