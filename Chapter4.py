import cv2
import numpy as np

#Shapes and Texts#

img = np.zeros((512,512,3),np.uint8)
#Changing color from Black to Blue#

img[:] = (255,0,0)
#line

cv2.line(img,(0,0),(img.shape[1],img.shape[0]),(255,255,125),3)
cv2.rectangle(img,(0,0),(250,250),(0,255,255), cv2.FILLED)
cv2.circle(img,(250,250),150,(25,250,120),cv2.FILLED)
cv2.putText(img,"Safir",(250,250),cv2.FONT_HERSHEY_COMPLEX,2,(250,250,250),2)
cv2.imshow("Image", img)
cv2.waitKey(0)