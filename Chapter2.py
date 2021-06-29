import cv2
import numpy as np

#Grayscale# #Blur Canny Dilate Erode#

img = cv2.imread("lena.png")
imgGray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
imgBlur = cv2.GaussianBlur(imgGray,(7,7),0)
imgCanny = cv2.Canny(imgBlur,75,75)

kernel = np.ones((5, 5), np.uint8)

imgDilate = cv2.dilate(imgCanny, kernel, iterations=1)
imgErode = cv2.erode(imgDilate,kernel,iterations=1)

cv2.imshow("Original Image", img)
cv2.imshow("Gray Image", imgGray)
cv2.imshow("Blur Image", imgBlur)
cv2.imshow("Canny Image", imgCanny)
cv2.imshow("Dilate Image", imgDilate)
cv2.imshow("Erode Image", imgErode)

cv2.waitKey(0)