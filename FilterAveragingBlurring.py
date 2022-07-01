import cv2
import numpy as np

img = cv2.imread('./img/girl.jpg')

#5x5 평균 필터 커널 생성
kernel0 = np.array([ [0.04, 0.04, 0.04, 0.04, 0.04],
                    [0.04, 0.04, 0.04, 0.04, 0.04],
                    [0.04, 0.04, 0.04, 0.04, 0.04],
                    [0.04, 0.04, 0.04, 0.04, 0.04],
                    [0.04, 0.04, 0.04, 0.04, 0.04] ])

#5 필터 커널 생성
kernel1 = np.array([ [0.4, 0.4, 0.4, 0.4, 0.4],
                    [0.4, 0.4, 0.4, 0.4, 0.4],
                    [0.4, 0.4, 0.4, 0.4, 0.4],
                    [0.4, 0.4, 0.4, 0.4, 0.4],
                    [0.4, 0.4, 0.4, 0.4, 0.4] ])

# 5x5 평균 필터 커널 생성
kernel2 = np.ones((5,5))/5**2

# 필터 적용
blured0 = cv2.filter2D(img, -1, kernel0)
blured1 = cv2.filter2D(img, -1, kernel1)
blured2 = cv2.filter2D(img, -1, kernel2)

# 결과 출력
cv2.imshow('origin', img)
cv2.imshow('avrg blur0', blured0)
cv2.imshow('avrg blur1', blured1)
cv2.imshow('avrg blur2', blured2)
cv2.waitKey()
cv2.destroyAllWindows()