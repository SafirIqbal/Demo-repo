import cv2 as cv
import numpy as np

img = cv.imread("Resources//lambo.png")

#######Translation######
def translate(img,x,y):
    transmat = np.float32([[1,0,x],[0,1,y]])
    dimensions = (img.shape[1],img.shape[0])
    return cv.warpAffine(img,transmat,dimensions)

# translated = translate(img,100,100)
# cv.imshow("Result", translated )
# cv.waitKey(0)

#######Rotation#######
def rotate(img,angle,rotPoint=None):
    (height,width)= (img.shape[0:2])
    if rotPoint is None:
        rotPoint = (width//2,height//2)
    rotMat = cv.getRotationMatrix2D(rotPoint,angle,1.0)
    dimensions = (width,height)
    return cv.warpAffine(img,rotMat,dimensions)

# rotated = rotate(img,90)
# cv.imshow("Rotated", rotated)
# cv.waitKey(0)


######Flip######

flip = cv.flip(img,0)
cv.imshow("Flipped", flip)
cv.waitKey(0)