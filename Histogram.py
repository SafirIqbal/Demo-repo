import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

img = cv.imread("Resources/test.png")

color = ('b','g','r')
plt.figure()
plt.title('Color Histogram')
plt.xlabel('Bins')
plt.ylabel('# of Pixels')
cv.imshow("Result", img)
for i,col in enumerate(color):
    hist = cv.calcHist([img],[i],None,[256],[0,256])
    plt.xlim([0,256])
    plt.plot(hist,color=col)

plt.show()

cv.waitKey(0)