import cv2
import numpy as np

img = cv2.imread('image1.jpg')
#filteredImg = cv2.blur(img,(5,5))
#filteredImg = cv2.GaussianBlur(img,(5,5),0)
#filteredImg = cv2.medianBlur(img,5)
#filteredImg = cv2.bilateralFilter(img,5,75,75)#(src,dst,d,sigmaColor,sigmaSpace)

#sharpeningFilter = np.array([[-1,-1,-1],[-1,9,-1],[-1,-1,-1]])
#filteredImg = cv2.filter2D(img,-1,sharpeningFilter)

#Filter = np.array([[1,0,0],[0,0,0],[0,0,-1]])
#filteredImg = cv2.filter2D(img, -1, Filter)

#kernel = np.ones((5,5),np.uint8)
#filteredImg = cv2.erode(img,kernel,iterations = 1)

kernel = np.ones((5,5),np.uint8)
filteredImg = cv2.dilate(img,kernel,iterations = 1)

cv2.imshow('Image',filteredImg)
cv2.waitKey(0)
cv2.destroyAllWindows()