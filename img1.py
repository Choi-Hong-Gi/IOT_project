
import cv2

img_file = "./img/model.jpg" 
img = cv2.imread(img_file,
                 cv2.IMREAD_GRAYSCALE)

if img is not None: 
    cv2.imshow('model', img) 
    cv2.waitKey(0) 
    cv2.destroyAllWindows()
else:
    print("None Image file: ", 
          img_file)

