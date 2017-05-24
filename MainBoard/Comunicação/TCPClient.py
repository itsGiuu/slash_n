import socket
import time

TCP_IP = 'localhost'
TCP_PORT = 7009
BUFFER_SIZE = 1024
MESSAGE = "Teste python TCP client".encode('utf-8')

while True:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((TCP_IP, TCP_PORT))
    s.send(MESSAGE)
    data = s.recv(BUFFER_SIZE)
    s.close()
    print("received data:", data)
    time.sleep(2)