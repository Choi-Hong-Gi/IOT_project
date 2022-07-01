import sys
import PyQt5
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5 import uic

uiDialog='Calculator.ui'

class MyDialog(QDialog):
    
    strKeyin = ""
    NumA = 0
    NumB = 0
    Cmd = ""
    
    def __init__(self):
        QDialog.__init__(self,None)
        uic.loadUi(uiDialog,self)
        
        
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
        self.pushButton_00.clicked.connect(self.buttonClick_00)
        self.pushButton_Dot.clicked.connect(self.buttonClick_Dot)
        self.pushButton_BS.clicked.connect(self.buttonClick_BS)
        self.pushButton_AC.clicked.connect(self.buttonClick_AC)
        self.pushButton_C.clicked.connect(self.buttonClick_C)
        self.pushButton_Plus.clicked.connect(self.buttonClick_Plus)
        self.pushButton_Minus.clicked.connect(self.buttonClick_Minus)
        self.pushButton_Devide.clicked.connect(self.buttonClick_Devide)
        self.pushButton_Multi.clicked.connect(self.buttonClick_Multi)
        self.pushButton_Equ.clicked.connect(self.buttonClick_Equ)
        
        
        
    def buttonClick_1(self):
        self.lineEdit.setText(self.lineEdit.text() + '1')
        MyDialog.strKeyin += '1'
    def buttonClick_2(self):
        self.lineEdit.setText(self.lineEdit.text() + '2')
        MyDialog.strKeyin += '2'
    def buttonClick_3(self):
        self.lineEdit.setText(self.lineEdit.text() + '3')
        MyDialog.strKeyin += '3'
    def buttonClick_4(self):
        self.lineEdit.setText(self.lineEdit.text() + '4')
        MyDialog.strKeyin += '4'
    def buttonClick_5(self):
        self.lineEdit.setText(self.lineEdit.text() + '5')
        MyDialog.strKeyin += '5'
    def buttonClick_6(self):
        self.lineEdit.setText(self.lineEdit.text() + '6')
        MyDialog.strKeyin += '6'
    def buttonClick_7(self):
        self.lineEdit.setText(self.lineEdit.text() + '7')
        MyDialog.strKeyin += '7'
    def buttonClick_8(self):
        self.lineEdit.setText(self.lineEdit.text() + '8')
        MyDialog.strKeyin += '8'
    def buttonClick_9(self):
        self.lineEdit.setText(self.lineEdit.text() + '9')
        MyDialog.strKeyin += '9'
    def buttonClick_0(self):
        if(MyDialog.strKeyin == '0'):
            self.lineEdit.setText(self.lineEdit.text() + '')
            MyDialog.strKeyin += ''
        else:    
            self.lineEdit.setText(self.lineEdit.text() + '0')
            MyDialog.strKeyin += '0'
    def buttonClick_00(self):
        if(MyDialog.strKeyin == '0'):
            self.lineEdit.setText(self.lineEdit.text() + '')
            MyDialog.strKeyin += ''
        elif(MyDialog.strKeyin == ''):
            self.lineEdit.setText(self.lineEdit.text() + '0')
            MyDialog.strKeyin += '0'
        else:    
            self.lineEdit.setText(self.lineEdit.text() + '00')
            MyDialog.strKeyin += '00'
    def buttonClick_Dot(self):
        if('.' in MyDialog.strKeyin):
            MyDialog.strKeyin += ''
            self.lineEdit.setText(self.lineEdit.text() + '')
        else:
            if(MyDialog.strKeyin == ''):
                MyDialog.strKeyin += '0.'
                self.lineEdit.setText(self.lineEdit.text() + '0.')
            else:
                MyDialog.strKeyin += '.'
                self.lineEdit.setText(self.lineEdit.text() + '.')
    def buttonClick_BS(self):
        self.lineEdit.setFocus()
        self.lineEdit.backspace()
        if(len(MyDialog.strKeyin) > 0):
            MyDialog.strKeyin = MyDialog.strKeyin[0:len(MyDialog.strKeyin)-1]
    def buttonClick_AC(self):
        self.lineEdit.setText('')
        MyDialog.strKeyin = ""
    def buttonClick_C(self):
        self.lineEdit.setText('')
        MyDialog.strKeyin = ""
        MyDialog.NumA = 0
    def buttonClick_Plus(self):
        if(MyDialog.strKeyin != ""):
            MyDialog.NumA = int(MyDialog.strKeyin)
            MyDialog.NumB = 0
            MyDialog.Cmd = "+"
            MyDialog.strKeyin = ""
            self.lineEdit.setText('')
        elif(MyDialog.strKeyin == "" and MyDialog.Cmd != ""):
            MyDialog.NumB = 0
            MyDialog.Cmd = "+"
            MyDialog.strKeyin = ""
            self.lineEdit.setText('')
    def buttonClick_Minus(self):
        if(MyDialog.strKeyin != ""):
            MyDialog.NumA = int(MyDialog.strKeyin)
            MyDialog.NumB = 0
            MyDialog.Cmd = "-"
            MyDialog.strKeyin = ""
            self.lineEdit.setText('')
        elif(MyDialog.strKeyin == "" and MyDialog.Cmd != ""):
            MyDialog.NumB = 0
            MyDialog.Cmd = "-"
            MyDialog.strKeyin = ""
            self.lineEdit.setText('')
    def buttonClick_Devide(self):
        if(MyDialog.strKeyin != ""):
            MyDialog.NumA = int(MyDialog.strKeyin)
            MyDialog.NumB = 0
            MyDialog.Cmd = "/"
            MyDialog.strKeyin = ""
            self.lineEdit.setText('')
        elif(MyDialog.strKeyin == "" and MyDialog.Cmd != ""):
            MyDialog.NumB = 0
            MyDialog.Cmd = "/"
            MyDialog.strKeyin = ""
            self.lineEdit.setText('')
    def buttonClick_Multi(self):
        if(MyDialog.strKeyin != ""):
            MyDialog.NumA = int(MyDialog.strKeyin)
            MyDialog.NumB = 0
            MyDialog.Cmd = "*"
            MyDialog.strKeyin = ""
            self.lineEdit.setText('')
        elif(MyDialog.strKeyin == "" and MyDialog.Cmd != ""):
            MyDialog.NumB = 0
            MyDialog.Cmd = "*"
            MyDialog.strKeyin = ""
            self.lineEdit.setText('')
    def buttonClick_Equ(self):
        if(MyDialog.Cmd != ""):
            MyDialog.NumB = int(MyDialog.strKeyin)
            self.MathGo()
    def MathGo(self):
        result = 0
        
        if(MyDialog.Cmd == "+"):
            result = MyDialog.NumA + MyDialog.NumB
        elif(MyDialog.Cmd == "-"):
            result = MyDialog.NumA - MyDialog.NumB
        elif(MyDialog.Cmd == "/"):
            result = MyDialog.NumA / MyDialog.NumB
        elif(MyDialog.Cmd == "*"):
            result = MyDialog.NumA * MyDialog.NumB
        else:
            result = 0
        
        self.lineEdit.setText(str(result))
        MyDialog.NumB = 0
        MyDialog.strKeyin = str(result)
        MyDialog.Cmd = ""
    

if __name__ == '__main__':
    app=QApplication(sys.argv)
    form=MyDialog()
    form.show()
    app.exec()
