import cv2
import numpy as np

img = cv2.imread('./img/fish.jpg')

#원본
cv2.imshow('original', img)

rows,cols = img.shape[0:2] # 영상 크기
dx, dy = 100, 50 # 이동 픽셀 거리

#변환 행렬
mtrx = np.float32([[1, 0, dx],[0, 1, dy]])

#단순 이동
dst = cv2.warpAffine(img, mtrx, (cols+dx, rows+dy))
cv2.imshow('trans',dst)

#탈락 외곽 픽셀 파랑색 보정
dst2 = cv2.warpAffine(img, mtrx, (cols+dx, rows+dy), None, cv2.INTER_LINEAR, cv2.BORDER_CONSTANT, (255,0,0) )
cv2.imshow('BORDER_CONSTATNT', dst2)

#탈락 외곽 픽셀 원본 반사 보정
dst3 = cv2.warpAffine(img, mtrx, (cols+dx, rows+dy), None, cv2.INTER_LINEAR, cv2.BORDER_REFLECT)
cv2.imshow('BORDER_FEFLECT', dst3)  

cv2.waitKey(0)
cv2.destroyAllWindows()