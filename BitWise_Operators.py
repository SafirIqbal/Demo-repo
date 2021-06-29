import cv2 as cv
import numpy as np

blank = np.zeros((400,400), np.uint8)
rectangle = cv.rectangle(blank.copy(),(30,30),(370,370),255,cv.FILLED)
circle = cv.circle(blank.copy(),(200,200),200,255,cv.FILLED)

#Bitwise and operator#
######Intersecting Regions######
bit_wise_and = cv.bitwise_and(rectangle,circle)
cv.imshow("BitWise And",bit_wise_and)

#Bitwise Or#
######Intersecting Regions and Non intersecting regions#######
bit_wise_or = cv.bitwise_or(rectangle,circle)
cv.imshow("BitWise Or", bit_wise_or)

#BitWise XOR#
######Non intersecting Regions#####
bit_wise_xor = cv.bitwise_xor(rectangle,circle)
cv.imshow("XOR",bit_wise_xor)

#BitWise Not#
######Inverting the binary colors#####

bit_wise_not = cv.bitwise_not(rectangle)
cv.imshow("Not", bit_wise_not)

cv.imshow("Rectangle", rectangle)
cv.imshow("Circle", circle)
cv.waitKey(0)