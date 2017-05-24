import socket

UDP_IP = "192.168.137.1"
UDP_PORT = 7008

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind(('', UDP_PORT))
print(UDP_IP)
print(UDP_PORT)
print("Server Start")
while True:
    data, addr = sock.recvfrom(1024) # buffer size is 1024
    #sock.sendto(data,(addr[0],addr[1]))
    print(data, addr[0],addr[1])