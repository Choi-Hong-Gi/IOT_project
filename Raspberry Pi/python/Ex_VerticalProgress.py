import sys
import PyQt5
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5 import uic

uiWidget = 'Ex_VerticalProgress.ui'

class MyWindow(QWidget):
    num = 0
    
    def __init__(self):
        super().__init__()
        uic.loadUi(uiWidget, self)
        
        self.progressBar_1.setStyleSheet('QProgressBar::chunk{background-color:blue;}')
        self.progressBar_2.setStyleSheet('QProgressBar::chunk{background-color:black;}')
        
        self.pushButton_1.clicked.connect(self.buttonClick_1)
        self.pushButton_2.clicked.connect(self.buttonClick_2)
        self.pushButton_3.clicked.connect(self.buttonClick_3)
        self.pushButton_4.clicked.connect(self.buttonClick_4)
        self.pushButton_5.clicked.connect(self.buttonClick_5)
        self.pushButton_6.clicked.connect(self.buttonClick_6)
        self.pushButton_7.clicked.connect(self.buttonClick_7)
        self.pushButton_8.clicked.connect(self.buttonClick_8)
        self.pushButton_9.clicked.connect(self.buttonClick_9)
        self.pushButton_0.clicked.connect(self.buttonClick_0)
        self.pushButton_ENTER.clicked.connect(self.buttonClick_ENTER)
        self.pushButton_CLR.clicked.connect(self.buttonClick_CLR)
    
    def buttonClick_ENTER(self):
        if self.radioButton_1.isChecked( ):
            if (int(self.lineEdit.text( )) <= 100 and int(self.lineEdit.text( )) >=0):
                self.lcdNumber_1.display(self.lineEdit.text( ))
                self.progressBar_1.setValue(int(self.lineEdit.text( )))
            else:
                pass
        elif self.radioButton_2.isChecked( ):
            if (int(self.lineEdit.text( )) <= 100 and int(self.lineEdit.text( )) >=0):
                self.lcdNumber_2.display(self.lineEdit.text( ))
                self.progressBar_2.setValue(int(self.lineEdit.text( )))
            else:
                pass
        else:
            pass
        
    def buttonClick_CLR(self):
        self.lineEdit.setText('')      
    
    def buttonClick_1(self):
        self.lineEdit.setText(self.lineEdit.text() + '1')

    def buttonClick_2(self):
        self.lineEdit.setText(self.lineEdit.text() + '2')

    def buttonClick_3(self):
        self.lineEdit.setText(self.lineEdit.text() + '3')

    def buttonClick_4(self):
        self.lineEdit.setText(self.lineEdit.text() + '4')

    def buttonClick_5(self):
        self.lineEdit.setText(self.lineEdit.text() + '5')

    def buttonClick_6(self):
        self.lineEdit.setText(self.lineEdit.text() + '6')

    def buttonClick_7(self):
        self.lineEdit.setText(self.lineEdit.text() + '7')

    def buttonClick_8(self):
        self.lineEdit.setText(self.lineEdit.text() + '8')

    def buttonClick_9(self):
        self.lineEdit.setText(self.lineEdit.text() + '9')

    def buttonClick_0(self):
        self.lineEdit.setText(self.lineEdit.text() + '0')



if __name__ == '__main__':
    app = QApplication(sys.argv)
    form = MyWindow()
    form.show()
    sys.exit(app.exec())