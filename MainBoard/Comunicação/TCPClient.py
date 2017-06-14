import socket
import time
import json

TCP_IP = '192.168.100.12'
TCP_PORT = 8025
BUFFER_SIZE = 1024

MESSAGE1 = '''{
			"responseType": "updateSingle",
			"info":[14101350,43]
			}'''.encode('utf-8')
			
MESSAGE2 = '''{
			"responseType": "updateMult",
			"size":3,
			"students":[
				{"matr":13105012, "cred":54},
				{"matr":13175923, "cred":194},
				{"matr":13458984, "cred":744}
			]}'''.encode('utf-8')
			
MESSAGE3 = '''{
			"responseType": "getUpdates"
			}'''.encode('utf-8')
			
			
			
message = 1


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))



if message == 1:
	s.send(MESSAGE1)
elif message == 2:
	s.send(MESSAGE2)
elif message == 3:
	s.send(MESSAGE3)
	data = s.recv(BUFFER_SIZE)
	parsed_json = json.loads(data.decode('utf-8'))
	print(parsed_json['responseType'])
	print(parsed_json['size'])
	print(parsed_json['entradas'])


s.close()


