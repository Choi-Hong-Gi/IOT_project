import cv2

img = cv2.imread('./img/blank_500.jpg')

cv2.putText(img, "Plain" , (200, 50), cv2.FONT_HERSHEY_PLAIN, 2, ( 0 , 0, 0))
cv2.putText(img, "Simplex", (50, 70), cv2.FONT_HERSHEY_SIMPLEX, 1, ( 125 , 125, 75))
cv2.putText(img, "Duplex", (30, 130), cv2.FONT_HERSHEY_DUPLEX, 1, ( 200 , 15, 170))
cv2.putText(img, "Simplex", (200, 130), cv2.FONT_HERSHEY_SIMPLEX, 2, (0,0, 250))
cv2.putText(img, "Complex Small", (150,180),
            cv2.FONT_HERSHEY_COMPLEX_SMALL, 1, ( 0 , 12, 160))
cv2.putText(img, "Complex", (50, 220),cv2.FONT_HERSHEY_COMPLEX, 1, ( 100 , 25, 255))
cv2.putText(img, "Triplex" , (20, 270),cv2.FONT_HERSHEY_TRIPLEX, 1, ( 200 , 100, 100))
cv2.putText(img, "Complex", (200, 280), cv2.FONT_HERSHEY_TRIPLEX, 2 , ( 0 , 0 ,255))


cv2.putText(img, " Sc riptSimplex", (50, 330),
            cv2.FONT_HERSHEY_SCRIPT_SIMPLEX, 1, ( 140 , 100, 50))
cv2.putText(img, " Sc riptComplex", (150, 370),
            cv2.FONT_HERSHEY_SCRIPT_COMPLEX, 1, ( 10 , 120, 180))

cv2.putText(img, "Plain Italic" , (150, 420), cv2.FONT_HERSHEY_PLAIN | 
            cv2.FONT_ITALIC, 1, ( 0 , 255, 0))
cv2.putText(img, "Complex Italic" , (50, 470), cv2.FONT_HERSHEY_COMPLEX | 
            cv2.FONT_ITALIC, 1, ( 255 , 0, 0))

cv2.imshow('draw text', img) 
cv2.waitKey()
cv2.destroyAllWindows()

