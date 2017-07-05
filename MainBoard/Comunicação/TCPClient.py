import socket
import time
import json


TCP_IP = '192.168.137.250'
TCP_PORT = 8025
BUFFER_SIZE = 2048

MESSAGE1 = '''[{"ThereIs": "updateSingle",
			"info":[14101350,43]
			}]'''.encode('utf-8')

			
MESSAGE2 = '''[{"ThereIs": "updateMult",
			"size":31,
			"students":[
				{"matr":100, "cred":54},
				{"matr":101, "cred":744},
				{"matr":102, "cred":8744},
				{"matr":103, "cred":7944},
				{"matr":14101336, "cred":744},
				{"matr":14740, "cred":7446},
				{"matr":14850, "cred":7744},
				{"matr":14560, "cred":744},
				{"matr":14760, "cred":7144},
				{"matr":1470, "cred":7424},
				{"matr":143560, "cred":3744},
				{"matr":14470, "cred":17444},
				{"matr":14546840, "cred":2744},
				{"matr":1420, "cred":3744},
				{"matr":14460, "cred":4744},
				{"matr":146240, "cred":5744},
				{"matr":14422101351, "cred":54},
				{"matr":1441230, "cred":45744},
				{"matr":142130, "cred":1744},
				{"matr":1451230, "cred":2744},
				{"matr":1416320, "cred":3744},
				{"matr":147540, "cred":7444},
				{"matr":148450, "cred":67544},
				{"matr":145960, "cred":7744},
				{"matr":147460, "cred":8744},
				{"matr":14720, "cred":7944},
				{"matr":1438560, "cred":9744},
				{"matr":144570, "cred":0744},
				{"matr":145346840, "cred":0744},
				{"matr":14260, "cred":6744},
				{"matr":141640, "cred":7744},
				{"matr":162440, "cred":4744}
			]}]'''.encode('utf-8')
			
MESSAGE3 = '''[{"ThereIs": "getUpdates"
			}]'''.encode('utf-8')			
MESSAGE4 = '''[{"ThereIs": "setVerification",
			"verification": 3}]'''.encode('utf-8')			
MESSAGE5 = '''[{"ThereIs": "getOcupacao"}]'''.encode('utf-8')
MESSAGE6 = '''[{"ThereIs": "printABB"}]'''.encode('utf-8')
MESSAGE7 = '''[{"ThereIs": "openCatraca"}]'''.encode('utf-8')
MESSAGE8 = '''[{"ThereIs": "printHeapSize"}]'''.encode('utf-8')
MESSAGE9 = '''[{"ThereIs": "WhatDoYouWant"}]'''.encode('utf-8')
MESSAGE10 = json_str = '''
[
    {
        "HowMuch": 4,
        "ThereIs": "Aluno"
    },
    [
        {
            "Matricula": 14101350,
            "Nome": "Roberto",
            "creditsCard": 2345679872,
            "creditsMobile": 199,
            "senhaApp": ""
        },
        {
            "Matricula": 14101345,
            "Nome": "Natan Votre",
            "creditsCard": 500,
            "creditsMobile": 120,
            "senhaApp": ""
        },
        {
            "Matricula": 14101336,
            "Nome": "Giulia",
            "creditsCard": 990033,
            "creditsMobile": 98,
            "senhaApp": ""
        },
        {
            "Matricula": 14101300,
            "Nome": "Claudio Vilas Boas",
            "creditsCard": 330.1000061035156,
            "creditsMobile": 120,
            "senhaApp": ""
        }asd
    ]
]
'''.encode('utf-8')

MESSAGE11 = '''[
    {
        "LEDs": 25,
        "Matricula": 14101336,
        "ThereIs": "LEDs"
    }
]
'''.encode('utf-8')


message = -1
while(message != 0):			
	print("\n\n\n\n\n\n ------------------------------ \nType in command: ")
	arg = input()
	try:
		message = int(arg)
	except:
		print("Error on input")
		message = -1
		
	if(message == 4):
		print("Enter verification pattern: ")
		try:
			pattern = int(input())
		except:
			print("pattern input error")
			pattern = 0
		MESSAGE4 = '''[{"ThereIs": "setVerification",
			"verification": '''+str(pattern)+"}]"
		MESSAGE4 = MESSAGE4.encode('utf-8')

	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect((TCP_IP, TCP_PORT))



	if message == 1:
		s.send(MESSAGE1)
	elif message == 2:
		s.send(MESSAGE2)
	elif message == 3:
		s.send(MESSAGE3)
		data = s.recv(BUFFER_SIZE)
		print(data)
		parsed_json = json.loads(data.decode('utf-8'))
		print(parsed_json);
	elif message == 4:
		s.send(MESSAGE4)
	elif message == 5:
		s.send(MESSAGE5)
		data = s.recv(BUFFER_SIZE)
		parsed_json = json.loads(data.decode('utf-8'))
		print(parsed_json)
		print(parsed_json['ThereIs'])
		print(parsed_json['ocupacao'])
	elif message == 6:
		s.send(MESSAGE6)
	elif message == 7:
		s.send(MESSAGE7)
	elif message == 8:
		s.send(MESSAGE8)
	elif message == 9:
		s.send(MESSAGE9)
		data = s.recv(BUFFER_SIZE)
		parsed_json = json.loads(data.decode('utf-8'))
		print(parsed_json[0]['ThereIs'])
	elif message == 10:
		s.send(MESSAGE10)	
	elif message == 11:
		s.send(MESSAGE11)
		data = s.recv(BUFFER_SIZE)
		print(data)
		parsed_json = json.loads(data.decode('utf-8'))
		print(parsed_json)
	s.close()


