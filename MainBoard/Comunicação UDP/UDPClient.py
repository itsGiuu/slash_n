import socket, time  # Import socket module

port = 1234  # Reserve a port for your service.
IP = "192.168.100.4"

sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

print("start")
i=280987987
while(1):
    i+=1
    message = (str(i)+"\n").encode('utf-8')
    sock.sendto(message,(IP,port))
    data=sock.recv(1024)
    print(data.decode('utf-8'))
