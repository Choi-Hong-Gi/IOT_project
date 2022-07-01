import cv2
import numpy as np

thresh = 15
max_diff = 5

cap = cv2.VideoCapture(0)

ret, a = cap.read()
ret, b = cap.read()

while True:
    ret, c = cap.read()
    
    if not ret:
        break
    
    draw = c.copy()
    
    a_gray = cv2.cvtColor(a, cv2.COLOR_BGR2GRAY)
    b_gray = cv2.cvtColor(b, cv2.COLOR_BGR2GRAY)
    c_gray = cv2.cvtColor(c, cv2.COLOR_BGR2GRAY)
    
    diff1 = cv2.absdiff(a_gray, b_gray)
    diff2 = cv2.absdiff(b_gray, c_gray)
    
    ret, diff1_t = cv2.threshold(diff1, thresh, 255, cv2.THRESH_BINARY)
    ret, diff2_t = cv2.threshold(diff2, thresh, 255, cv2.THRESH_BINARY)
    
    diff = cv2.bitwise_and(diff1_t, diff2_t)
    
    k = cv2.getStructuringElement(cv2.MORPH_CROSS, (3,3))
    diff = cv2.morphologyEx(diff, cv2.MORPH_OPEN, k)
    
    diff_cnt = cv2.countNonZero(diff)
    if diff_cnt> max_diff:
        nzero = np.nonzero(diff)
        cv2.rectangle(draw, (min(nzero[1]), min(nzero[0])), (max(nzero[1]), max(nzero[0])), (0,0,255), 1)
        cv2.putText(draw, "Motion Detected", ( min(nzero[1]), min(nzero[0]) ), cv2.FONT_HERSHEY_DUPLEX, 1, (0,0,255), 1)
    
    cv2.imshow('mosion sensor', draw)
    
    a = b
    b = c
    
    if cv2.waitKey(1) & 0xFF == 27:
        break
    
cap.release() 
cv2.destroyAllWindows()
