import json




json_str = '''
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
        }
    ]
]
'''


json2 = '''[{"ThereIs":"updateAlunos","HowMuch":6},[{"matricula":945445,"credit":"card"},{"matricula":11445,"credit":"card"},{"matricula":445,"credit":"card"},{"matricula":3123,"credit":"card"},{"matricula":25445,"credit":"card"},{"matricula":101,"credit":"card"}]]

'''

parsed_json2 = json.loads(json2)
print(parsed_json2[1][0])
#parsed_json = json.loads(json_str)
#print(parsed_json[1][3])
