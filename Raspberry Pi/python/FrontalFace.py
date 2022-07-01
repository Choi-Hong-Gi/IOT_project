import cv2
import numpy as np

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

img = cv2.imread('KakaoTalk_20180418_101706900.jpg')

gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
faces = face_cascade.detectMultiScale(gray,1.1,5)

count = 1
for(x,y,w,h) in faces:
    cv2.rectangle(img,(x,y+15),(x+60,y+30),(0,0,0),-1)
    #cv2.putText(img,str(count),(x,y-5),cv2.FONT_HERSHEY_SIMPLEX,0.5,(255,255,0),2)
    count += 1

print("Detected person's number is => " + str(count-1))

cv2.imshow('Image', img)
cv2.waitKey(0)
cv2.destroyAllWindows()