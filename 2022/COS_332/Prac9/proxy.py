#!/usr/bin/env python3

import socket
import sys
import telnetlib
import time
from getpass_asterisk.getpass_asterisk import getpass_asterisk

def findPS(sline:str):
    return sline.upper.find('PS')

# find ps
# find last linked command to the right
# delete from command to ps

def stripPS(sline:str):
    compound = ["&&", "||"]
    isolated = ["&", ";"]
    sline = sline.upper()
    arr = sline.split()
    while 'PS' in arr:
        i = arr.index("PS")
        if i == len(arr)-1:
            arr.pop(len(arr)-1)
            break
        if i > 0:
            if arr[i-1] in compound:
                arr.pop(i-1)
                i = arr.index("PS")
            if arr[i-1] in isolated[0]:
                arr.pop(i-1)
                arr.pop(i-1)
                continue
        if i + 2 < len(arr):
            j = i + 1
            while True:
                if j >= len(arr):
                    arr = arr[0:i-1]
                    break
                if arr[j] in compound:
                    j = j + 2
                else:
                    j = j-1
                    for k in range(j, arr.index('PS'), -1):
                        arr.pop(k)
                    arr.pop(i)
                    break
        elif i + 1 == len(arr) - 1:
            arr.pop(len(arr)-1)
            arr.pop(len(arr)-1)
    return " ".join(arr).lower()

def connect(hostname, port, username, password, command):
    tn = telnetlib.Telnet(hostname, port)

    tn.read_until(b'ogin:')
    tn.write(username.encode('utf-8') + b'\r')

    tn.read_until(b'assword:')
    tn.write(password.encode('utf-8') + b'\r')

    i, m, p = tn.expect([br'Login incorrect', br'\$ '])
    if i == 0:
        print("Credentials incorrect")
    else:
        tn.write(stripPS(command).encode('utf-8') + b'\r')
        time.sleep(0.5)
        tn.write(b'exit\r')
        return tn.read_all().decode('utf-8')

    tn.close()

if __name__ == "__main__":
    # if len(sys.argv) < 3:
    #     print("Usage: python proxy.py hostname port username")
    #     exit()

    #TODO: Not working --> print(stripPS("ls -alh && ps -aux && cat text.txt"))
    #TODO: Is working  --> print(stripPS("ls & ps & cat test.txt"))
    # print(stripPS("ls & ps & cat test.txt"))

    # hostname = sys.argv[1]
    # port = sys.argv[2]
    # username = sys.argv[3]
    # password = getpass_asterisk("Password: ")

    hostname = ''
    port = ''
    username = ''
    password = ''
    count = 0

    HOST = ''

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.setblocking(False)
    server.bind((HOST, 5555))
    server.listen(5)

    connections = []
    out = ''

    while True:
        try:
            connection, address = server.accept()
            connection.setblocking(False)
            connections.append(connection)
        except BlockingIOError:
            pass

        for connection in connections:
            try:
                if (count == 0):
                    connection.send(b'Client> ')
                    count+= 1
                message = connection.recv(4096)
                message = message.decode('utf-8').strip()

                if (message == ':quit'):
                    connection.close()
                    server.detach()
                    server.close()
                    sys.exit()
                elif (message.find('host:') != -1):
                    hostname = message.replace('host:', '')
                    out = f'Hostname has been set to: {hostname}\r\n'
                elif (message.find('port:') != -1):
                    port = message.replace('port:', '')
                    out = f'Port has been set to: {port}\r\n'
                elif (message.find('username:') != -1):
                    username = message.replace('username:', '')
                    out = f'Username has been set to: {username}\r\n'
                elif (message.find('password:') != -1):
                    password = message.replace('password:', '')
                    out = f'Password has been set to: {password}\r\n'
                else:
                    if ((hostname == '' or port == '' or username == '' or password == '') == False):
                        out = connect(hostname, port, username, password, message)
                    else:
                        out = f'One or more credentials not set.\r\n' \
                              f'Hostname: {hostname}\r\n' \
                              f'Port: {port}\r\n' \
                              f'Username: {username}\r\n' \
                              f'Password: {password}\r\n'
                count -= 1
            except BlockingIOError:
                continue

            for connection in connections:
                connection.send(out.encode('utf-8'))