import cv2
import numpy as np

#Resizing and Cropping

img = cv2.imread("lambo.png")
print(img.shape)
imgResize = cv2.resize(img,(300,300))
imgCrop = img[0:462,200:300]
cv2.imshow("Original Image", img)
cv2.imshow("Resize Image", imgResize)
cv2.imshow("Cropped Image", imgCrop)
cv2.waitKey(0)
