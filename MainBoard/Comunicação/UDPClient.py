import socket, time  # Import socket module

port = 7009  # Reserve a port for your service.
IP = "192.168.137.224"

sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

print("start")
i=0
while(1):
    i+=1
    message = (str(i)+"\n").encode('utf-8')
    sock.sendto(message,(IP,port))
    #data=sock.recv(1024)
    #print(data.decode('utf-8'))
    time.sleep(2)