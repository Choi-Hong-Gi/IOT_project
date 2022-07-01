import cv2
import numpy as np
'''
img = np.zeros((480,640,3),np.uint8)
#img = cv2.line(img,(0,479),(640,0),(210,210,100),1)
#line(img,start,end,color,thickness)
img = cv2.rectangle(img,(10,10),(630,470),(210,210,100),1)
#rectangle(img,start,end,color,thickness => -1 : fill)
img2 = cv2.circle(img,(240,320),100,(255,255,255),1)
#circle(img,center,radian,color,thickness => -1 : fill)
img3 = cv2.ellipse(img,(320,240),(100,50),0,0,270,255,-1)
#ellipse(img,center,axes,start angle, end angle, color, thickness)
'''
img = np.zeros((480,640,3),np.uint8)
pts = np.array([[100,20],[200,300],[400,300],[500,100]],np.int32)
pts = pts.reshape((-1,1,2))
img = cv2.polylines(img,[pts],True,(0,255,255))
img = cv2.putText(img, "Open CV",(80,300),cv2.FONT_HERSHEY_SIMPLEX,4,(255,255,255),10)

cv2.imshow('draw',img)
cv2.waitKey(0)
cv2.destroyAllWindows()