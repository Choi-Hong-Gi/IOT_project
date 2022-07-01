import sys
import PyQt5
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5 import uic
import random

uiDialog = 'MatPlotLibWidget.ui'

class MyDialog(QDialog):
    def __init__(self):
        QDialog.__init__(self,None)
        uic.loadUi(uiDialog,self)
        self.pushButton.clicked.connect(self.buttonClick)
        
    def buttonClick(self):
        radomNumbers = random.sample(range(0,10),10)
        self.widget.canvas.ax.clear()
        self.widget.canvas.ax.plot(radomNumbers)
        self.widget.canvas.draw()
        
if __name__ == '__main__':
    app = QApplication(sys.argv)
    form = MyDialog()
    form.show()
    app.exec()