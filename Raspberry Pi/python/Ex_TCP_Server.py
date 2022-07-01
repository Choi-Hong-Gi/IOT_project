from socket import *

host = "127.0.0.1"
port = 12345

s = socket(AF_INET,SOCK_STREAM)
s.bind((host,port))

s.listen(1) #number of client to accept
print("Listening for Connection: ", host)

while True:
    conn,addr = s.accept()
    print("Connection from", addr)
    conn.send(b'Connection OK')
    
conn.close()