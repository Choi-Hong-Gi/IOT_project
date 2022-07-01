import cv2
#import numpy as np

cap = cv2.VideoCapture(0)

tracker = cv2.TrackerKCF_create()

ret, frame = cap.read()

while True:
    rc = cv2.selectROI('frame', frame)
    tracker.init(frame, rc)
    
    ret, frame = cap.read()
    if not ret:
        break
    ret, rc = tracker.update(frame)
    
    rc = tuple([int(_) for _ in rc])
    
    cv2.rectangle(frame, rc, (0, 0, 255), 1)
    
    cv2.imshow('frame', frame)
    
    if cv2.waitKey(1) & 0xFF == 27:
        break
    
cap.release() 
cv2.destroyAllWindows()