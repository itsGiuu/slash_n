import socket
import threading

bind_ip = '192.168.100.13'
bind_port = 7009

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((bind_ip, bind_port))
server.listen(5)  # max backlog of connections



def handle_client_connection(client_socket):
    while(1):
        try:
            request = client_socket.recv(1024)
            print('Received {}'.format(request))
            client_socket.send('ACK!'.encode('utf-8'))
        except:
            client_socket.close()

while True:
    client_sock, address = server.accept()
    print('Accepted connection from {}:{}'.format(address[0], address[1]))
    client_handler = threading.Thread(
        target=handle_client_connection,
        args=(client_sock,)  # without comma you'd get a... TypeError: handle_client_connection() argument after * must be a sequence, not _socketobject
    )
    client_handler.start()