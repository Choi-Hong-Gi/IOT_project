import cv2

cap = cv2.VideoCapture(0)

mog = cv2.createBackgroundSubtractorMOG2(detectShadows=False)

while True:
    ret, frame = cap.read()
    mogframe = mog.apply(frame)
    
    cv2.imshow('camera', mogframe)
    
    contours, _ = cv2.findContours(mogframe, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[-2:]
    
    for c in contours:
        mmt = cv2.moments(c)
        if mmt['m00'] > 400:  # 넓이
            x, y, w, h = cv2.boundingRect(c)
            cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 1)
            cv2.drawContours(frame, c, -1, (0,0,255), 1)
            cx = int(mmt['m10']/mmt['m00'])
            cy = int(mmt['m01']/mmt['m00'])
            pos = '(' + str(cx) + ',' + str(cy) + ')'
            cv2.putText(frame, pos, (cx, cy), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 0), 1, cv2.LINE_AA)
    cv2.imshow('contours', frame)
        
    if cv2.waitKey(1) & 0xFF == 27:
        break

cap.release() 
cv2.destroyAllWindows()