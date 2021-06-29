import cv2
'''
#Read images#

img = cv2.imread("lena.png")
cv2.imshow("Image Lena", img)
cv2.waitKey(0)
'''
'''
#Video Capture#

cap = cv2.VideoCapture("Resources/test_video.mp4")
while True:
    success, img = cap.read()
    cv2.imshow("Video", img)
    if cv2.waitKey(1) == ord('q'):
        break
'''
#Webcam#

cap = cv2.VideoCapture(0)
# cap.set(3,640)
# cap.set(4,480)
cap.set(10,100) #For brightness
while True:
    success, img = cap.read()
    cv2.imshow("Webcam", img)
    if cv2.waitKey(1) == ord('q'):
        break
