import json


json_string = '''{"responseType": "updateMult",
			"size":3,
			"students":[
				{"matr":13105012, "cred":54},
				{"matr":13175923, "cred":194},
				{"matr":13458984, "cred":744}
			]}'''
parsed_json = json.loads(json_string)

d = {
    'first_name': 'Guido',
    'second_name': 'Rossum',
    'titles': ['BDFL', 'Developer'],
}

print(parsed_json["students"][1]["matr"])
print(json.dumps(d))