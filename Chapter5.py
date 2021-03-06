import cv2
import numpy as np


img = cv2.imread("cards.jpg")
w,h = 250,350
pts1 = np.float32([[111,219],[287,188],[154,482],[352,440]])
pts2 = np.float32([[0,0],[w,0],[0,h],[w,h]])
matrix = cv2.getPerspectiveTransform(pts1,pts2)
imgWarp = cv2.warpPerspective(img, matrix, (w, h))


cv2.imshow("Cards", img)
cv2.imshow("Warp", imgWarp)
cv2.waitKey(0)

