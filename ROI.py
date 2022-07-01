import cv2, numpy as np

img = cv2.imread('./img/sunset.jpg')

x=141; y=189; w=50; h=50 # roi 좌표

roi = img[y:y+h, x:x+w] # roi 지정
print(roi.shape) # roi shape, (50,50,3)

                          # 행, 열
cv2.rectangle(roi, (0,0), (h-1, w-1), (0,0,255)) # roi 전체에 사각형 그리기
cv2.imshow("img", img)

key = cv2.waitKey(0)
print(key)

cv2.destroyAllWindows()
