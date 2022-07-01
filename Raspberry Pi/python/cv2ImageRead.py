import cv2
import numpy as np

#img = cv2.imread('image1.jpg')
#img = cv2.imread('image1.jpg', cv2.IMREAD_GRAYSCALE)
#resizeImg = cv2.resize(img,(640,640))
#gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
'''
img = cv2.imread('image1.jpg', cv2.IMREAD_COLOR)
B_img, G_img, R_img = cv2.split(img)
zeroImg = np.zeros((img.shape[0],img.shape[1]), dtype = 'uint8')
mergeImg = cv2.merge([B_img,R_img,G_img])#BGR BRG is diffrent
'''
# 8bit, 8bit:0 to 255, 8bit:0 to 255, 8bit:0 to 255 => 24bit true color
'''
img = cv2.imread('image1.jpg')
resizeImg = cv2.resize(img,(640,640))
ret, threshHoldImage = cv2.threshold(resizeImg,200,255,cv2.THRESH_BINARY)
'''
#image binarization => by set of thresh point split bit images to 0, 1
'''
img = cv2.imread('image1.jpg')
resizeImg = cv2.resize(img,(640,640))
resizeGray = cv2.cvtColor(resizeImg,cv2.COLOR_BGR2GRAY)
ret, threshHoldImage = cv2.threshold(resizeGray,127,255,cv2.THRESH_BINARY)
'''
'''
img = cv2.imread('image1.jpg')
resizeImg = cv2.resize(img,(640,640))
resizeGray = cv2.cvtColor(resizeImg,cv2.COLOR_BGR2GRAY)
#mergeImg = cv2.add(resizeGray, +100)
mergeImg = cv2.multiply(resizeGray,2)
'''
'''
img_1 = cv2.imread('image1.jpg', cv2.IMREAD_GRAYSCALE)
img_2 = cv2.imread('image2.jpg', cv2.IMREAD_GRAYSCALE)
matchImg = cv2.bitwise_not(cv2.absdiff(img_1, img_2))
#minus image
'''

img = cv2.imread('image1.jpg')
maskImg = cv2.imread('mask-01.jpg')
resizeImg1 = cv2.resize(img,(320,320))
resizeImg2 = cv2.resize(maskImg,(320,320))


masked = cv2.bitwise_xor(resizeImg1,resizeImg2)


#cv2.imshow('photo', resizeImg)
#cv2.imshow('photo', gray)
#cv2.imshow('photo', img)
#cv2.imshow('photo', mergeImg)
#cv2.imshow('photo', threshHoldImage)
#cv2.imshow('photo', matchImg)
cv2.imshow('photo', masked)
           
cv2.waitKey(0)
cv2.destroyAllWindows()