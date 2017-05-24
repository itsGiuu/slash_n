import socket
import time

TCP_IP = '192.168.100.13'
TCP_PORT = 8023
BUFFER_SIZE = 1024
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))
i=0
while True:
    MESSAGE = str(i).encode('utf-8')
    MESSAGE = "server".encode('utf-8')
    i+=1
    s.send(MESSAGE)
    data = s.recv(BUFFER_SIZE)
    print("received data:", data)
    time.sleep(1)

s.close()
