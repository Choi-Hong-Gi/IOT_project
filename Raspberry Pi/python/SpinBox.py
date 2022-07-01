import sys
import PyQt5
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5 import uic

uiWidget = 'Ex_SliderUI.ui'

class MyWindow(QWidget):
    def __init__(self):
        super().__init__()
        uic.loadUi(uiWidget, self)
        
        #self.vSlider_1.setStyleSheet('QSlider::chunk{background-color:green;}')
        
        self.vSlider_1.valueChanged.connect(self.slide1_changed)
        self.vSlider_2.valueChanged.connect(self.slide2_changed)
        self.vSlider_3.valueChanged.connect(self.slide3_changed)
        self.vSlider_4.valueChanged.connect(self.slide4_changed)
        self.vSlider_5.valueChanged.connect(self.slide5_changed)
        
        self.spinBox_1.valueChanged.connect(self.spinBox1_changed)
        self.spinBox_2.valueChanged.connect(self.spinBox2_changed)
        self.spinBox_3.valueChanged.connect(self.spinBox3_changed)
        self.spinBox_4.valueChanged.connect(self.spinBox4_changed)
        self.spinBox_5.valueChanged.connect(self.spinBox5_changed)
        
    def slide1_changed(self):
        self.spinBox_1.setValue(self.vSlider_1.value())
    def slide2_changed(self):
        self.spinBox_2.setValue(self.vSlider_2.value())
    def slide3_changed(self):
        self.spinBox_3.setValue(self.vSlider_3.value())
    def slide4_changed(self):
        self.spinBox_4.setValue(self.vSlider_4.value())
    def slide5_changed(self):
        self.spinBox_5.setValue(self.vSlider_5.value())
        
    def spinBox1_changed(self):
        self.vSlider_1.setValue(self.spinBox_1.value())
    def spinBox2_changed(self):
        self.vSlider_2.setValue(self.spinBox_2.value())
    def spinBox3_changed(self):
        self.vSlider_3.setValue(self.spinBox_3.value())
    def spinBox4_changed(self):
        self.vSlider_4.setValue(self.spinBox_4.value())
    def spinBox5_changed(self):
        self.vSlider_5.setValue(self.spinBox_5.value())
            
if __name__ == '__main__':
    app = QApplication(sys.argv)
    form = MyWindow()
    form.show()
    sys.exit(app.exec())