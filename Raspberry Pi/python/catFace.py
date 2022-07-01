import cv2
import numpy as np

cat_cascade = cv2.CascadeClassifier('haarcascade_frontalcatface_extended.xml')

img = cv2.imread('88605_19436_1959.jpeg')
#img = cv2.imread('naver_com_20110617_181535.jpg')

gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
cat = cat_cascade.detectMultiScale(gray,1.1,5)

count = 1
for(x,y,w,h) in cat:
    cv2.rectangle(img,(x,y),(x+w,y+h),(255,255,0),2)
    cv2.putText(img,str(count),(x,y-5),cv2.FONT_HERSHEY_SIMPLEX,0.5,(255,255,0),2)
    count += 1

print("Detected cat's number is => " + str(count-1))

cv2.imshow('Image', img)
cv2.waitKey(0)
cv2.destroyAllWindows()