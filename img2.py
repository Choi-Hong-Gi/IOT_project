import cv2

img_file = "./img/model.jpg"
img = cv2.imread(img_file, cv2.IMREAD_GRAYSCALE) 

if img is not None: 
    cv2.imshow('model', img) 

    print('saving file.' )
    
    cv2.imwrite("./img/gray.jpg", img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()