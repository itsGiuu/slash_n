import socket

UDP_IP = "192.168.100.17"
UDP_PORT = 500

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))

while True:
   data, addr = sock.recvfrom(1024) # buffer size is 1024
   sock.sendto(data,(addr[0],addr[1]))
   print(data, addr[0],addr[1])