import cv2

cap = cv2.VideoCapture(0) 

if cap.isOpened():
    while True:
        ret, frame = cap.read()
        if ret:
            cv2.imshow('camera',frame)
            key = cv2.waitKey(1)
            if key == 27:
                break
        else:
            print('no frame!')
            break
else:
    print('no camera!')
    
cap.release() 
cv2.destroyAllWindows()
