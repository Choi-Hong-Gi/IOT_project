import cv2
import numpy as np
import time

cap = cv2.VideoCapture('./img/walking.avi')
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 480)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 320)

object_detector = cv2.createBackgroundSubtractorMOG2()

'''
fps = cap.get(cv2.CAP_PROP_FPS) # 프레임 수 구하기
delay = int(500/fps)
'''

prev_time = 0
FPS = 10

if cap.isOpened():
    ret = cap.read()

    while ret:
        ret, frame = cap.read()
        
        #cv2.waitKey(delay)
        current_time = time.time() - prev_time
        
        if (ret is True) and (current_time > 1./ FPS):
            print(time.time(), ' ', current_time, ' ', 1./ FPS)
   	
            prev_time = time.time()
       
            cv2.imshow('VideoCapture', frame)
            '''
            mask = object_detector.apply(frame)
            _, mask = cv2.threshold(mask, 254, 255, cv2.THRESH_BINARY)
            
            #cv2.imshow('mosion sensor', frame)
            '''
            if not ret:
                break
            
            if cv2.waitKey(1) & 0xFF == 27:
                break
        
cap.release()
cv2.destroyAllWindows()