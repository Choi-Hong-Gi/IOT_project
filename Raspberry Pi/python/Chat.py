import sys
from socket import *

myIP = "100.100.100.42"
port = 12345

Status = False

from threading import Thread

from PyQt5.QtWidgets import *
from PyQt5 import uic

uiDialog = 'TCP_Chat.ui'
bListen = False

class MyDialog(QDialog):
    def __init__(self):
        QDialog.__init__(self,None)
        uic.loadUi(uiDialog,self)
        
        self.lineEdit_1.setText('')
        self.lineEdit_2.setText(str(port))
        self.pushButton_1.setFocus
        self.pushButton_1.clicked.connect(self.Server_Listen)
        self.pushButton_2.clicked.connect(self.Connect)
        self.pushButton_3.clicked.connect(self.Send)
        self.server = None
        self.acceptor = None
        
        self.client = None
        
    def Server_Listen(self):
        if self.pushButton_1.text() == 'Listen':
            self.pushButton_1.setText('Close')
            
            self.server = socket(AF_INET, SOCK_STREAM)
            self.server.bind((myIP,port))
            self.bListen = True
            self.listenThread = Thread(target=self.listen,args = (self.server,))
            self.listenThread.start()
            self.textEdit.append('Start Listening')
            
        else:
            self.pushButton_1.setText('Listen')
            
            self.server = None
            bListen = False
            self.textEdit.append('Stop Listening')
            
    def listen(self, server):
        while True:
            self.server.listen(1)
            if self.acceptor is None:
                self.acceptor,addr = server.accept()
                strAddr = '    '.join(map(str, addr))
                msg = 'Connect: ' + strAddr
                self.textEdit.append(msg)
            else:
                recv = '[recv] ' + str(self.acceptor.recv(1024),encoding= 'utf-8')
                self.textEdit.append(recv)
                self.acceptor.send(b'Server OK')
                
        self.textEdit.append('Stop Server ')
        
    def Connect(self):
        if self.pushButton_2.text() == 'Connect':
            self.pushButton_2.setText('Close')
            self.client = socket(AF_INET,SOCK_STREAM)
            toIP = self.lineEdit_2.text()
            self.client.connect((toIP,port))
            
        else:
            self.pushButton_2.setText('Connect')
            self.client = None
            
    def Send(self):
        msg = str(self.lineEdit_3.text())
        send = '[send] ' + msg
        self.client.send(msg.encode('utf-8'))
        self.textEdit.append(send)
        self.lineEdit_3.setText("")
        
        
if __name__ == '__main__':
    app = QApplication(sys.argv)
    form = MyDialog()
    form.show()
    app.exec()
    
    