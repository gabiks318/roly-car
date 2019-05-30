import socket

def create_server(ip,port):
    sock=sock.socket(socket.AF_INET,socket.SOCK_DGRAM)
    sock.bind((ip,port))
    return sock

def listen(sock):
    data,adress=sock.recvfrom(1024)
    return data