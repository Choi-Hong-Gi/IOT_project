import cv2

# 트랙커 객체 생성자 함수 리스트
trackers = cv2.TrackerMIL_create

tracker = None
isFirst = True

cap = cv2.VideoCapture(0)

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        print('Cannot read video file')
        break
    img_draw = frame.copy()
    if tracker is None: # 트랙커 생성 안된 경우
        cv2.putText(img_draw, "Press the Space to set ROI!!", \
            (20,40), cv2.FONT_HERSHEY_SIMPLEX, 0.75,(0,0,255),1,cv2.LINE_AA)
    else:
        ok, bbox = tracker.update(frame)   # 새로운 프레임에서 추적 위치 찾기
        (x,y,w,h) = bbox
        
        if ok: # 추적 성공
            cv2.rectangle(img_draw, (int(x), int(y)), (int(x + w), int(y + h)), \
                          (0,255,0), 1, 1)
        else : # 추적 실패
            cv2.putText(img_draw, "Tracking fail.", (20,80), \
                        cv2.FONT_HERSHEY_SIMPLEX, 0.75,(0,0,255),1,cv2.LINE_AA)
    trackerName = tracker.__class__.__name__
    cv2.putText(img_draw, 'TrackerMIL' , (20,20), \
                 cv2.FONT_HERSHEY_SIMPLEX, 0.75, (0,255,0),1,cv2.LINE_AA)

    cv2.imshow('test', img_draw)
    key = cv2.waitKey(1) & 0xff
    # 스페이스 바 또는 비디오 파일 최초 실행
    if key == ord(' ') or (cap != 0 and isFirst): 
        isFirst = False
        roi = cv2.selectROI('test1', frame, False)  # 초기 객체 위치 설정
        if roi[2] and roi[3]:         # 위치 설정 값 있는 경우
            tracker = trackers()    #트랙커 객체 생성
            isInit = tracker.init(frame, roi)
    
    if cv2.waitKey(1) & 0xFF == 27:
        break
    
cap.release() 
cv2.destroyAllWindows()
    
#--------------------------------------------------------------------------------------------------------