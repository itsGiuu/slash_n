import socket
import time

TCP_IP = '192.168.100.12'
TCP_PORT = 8025
BUFFER_SIZE = 1024

MESSAGE1 = '{"responseType": "updateSingle", "info":[14101350,43]}'.encode('utf-8')
MESSAGE2 = '''{"responseType": "updateMult",
			"size":3,
			"students":[
				{"matr":13105012, "cred":54},
				{"matr":13175923, "cred":194},
				{"matr":13458984, "cred":744}
			]}'''.encode('utf-8')

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))
s.send(MESSAGE2)
#data = s.recv(BUFFER_SIZE)
#print("received data:", data)
time.sleep(3)

s.close()
