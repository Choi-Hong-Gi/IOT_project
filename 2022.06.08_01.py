import cv2
import sys

(major_ver, minor_ver, subminor_ver) = (cv2.__version__).split('.')


if __name__ == '__main__' :
    tracker_types = ['BOOSTING', 'MIL','KCF', 'TLD', 'MEDIANFLOW', 'GOTURN', 'MOSSE', 'CSRT']
    tracker_type = tracker_types[2]
    if int(minor_ver) < 3:
        tracker = cv2.Tracker_create(tracker_type)
    else:
        if tracker_type == 'BOOSTING':
            tracker = cv2.TrackerBoosting_create()
        if tracker_type == 'MIL':
            tracker = cv2.TrackerMIL_create()
        if tracker_type == 'KCF':
            tracker = cv2.TrackerKCF_create()
        if tracker_type == 'TLD':
            tracker = cv2.TrackerTLD_create()
        if tracker_type == 'MEDIANFLOW':
            tracker = cv2.TrackerMedianFlow_create()
        if tracker_type == 'GOTURN':
            tracker = cv2.TrackerGOTURN_create()
        if tracker_type == 'MOSSE':
            tracker = cv2.TrackerMOSSE_create()
        if tracker_type == "CSRT":
            tracker = cv2.TrackerCSRT_create()
            
    cap = cv2.VideoCapture(0) 
    ret, img = cap.read()
    bbox = cv2.selectROI(img, False)
    ret = tracker.init(img, bbox)

    if cap.isOpened():
        while True:
            ret, img = cap.read()
            timer = cv2.getTickCount()
            ret, bbox = tracker.update(img)
            fps = cv2.getTickFrequency() / (cv2.getTickCount() - timer);
            if ret:
                cv2.imshow('camera',img)
                if cv2.waitKey(1) & 0xFF == 27: #esc
                    break
            else:
                print('no frame!')
                break
    else:
        print('no camera!')
        
    cap.release() 
    cv2.destroyAllWindows()
