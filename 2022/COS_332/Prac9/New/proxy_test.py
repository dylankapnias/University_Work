import socket
import re
import time

######################
def reverseResponse(sline):
    sRet = ""
    while len(sline) > 0:
        if sline[0:2] == 'ff':
            sRet += "ff"
            sline = sline[2:len(sline)]
            # DO
            if sline[0:2] == 'fd':
                sRet += 'fc'
                sline = sline[2:len(sline)]
            # WILL
            elif sline[0:2] == 'fb':
                sRet += 'fe'
                sline = sline[2:len(sline)]
            sRet += sline[0:2]
            if len(sline) <= 2:
                sline = ""
            else:
                sline = sline[2:len(sline)]
    return sRet

######################
IAC = bytes.fromhex('ff')
DONT = bytes.fromhex('fe')
DO = bytes.fromhex('fd')
WONT = bytes.fromhex('fc')
WILL = bytes.fromhex('fb')
ECHO = bytes.fromhex('01')
SUPPRESS = bytes.fromhex('2d')
LOGOUT = bytes.fromhex('18')
######################

def connect(hostname, port, username, password):
    # with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    #     s.connect((hostname, int(port)))
    #     sline = ""
    #     sline = s.recv(256)
    #     while sline.find(b"Ubuntu") < 0:
    #         sline = sline.hex()
    #         sRet = reverseResponse(sline)
    #         toSend = bytes.fromhex(sRet)
    #         s.send(toSend)
    #         sline = s.recv(256)
    #         print(sline)
    #
    #     print(s.recv(4096).decode("UTF-8"))
    #     s.send(username.encode("UTF-8") + b'\r\n')
    #     time.sleep(0.5)
    #     print(s.recv(4096).decode("UTF-8"))
    #     s.send(password.encode("UTF-8") + b'\r\n')
    #     time.sleep(0.5)
    #     print(s.recv(4096).decode("UTF-8"))
    #
    #     # send = "exit\r\n"
    #     # s.send(send.encode("UTF-8"))
    #
    #     return s
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((hostname, int(port)))
    sline = ""
    sline = s.recv(256)
    while sline.find(b"Ubuntu") < 0:
        sline = sline.hex()
        sRet = reverseResponse(sline)
        toSend = bytes.fromhex(sRet)
        s.send(toSend)
        sline = s.recv(256)
        print(sline)

    print(s.recv(4096).decode("UTF-8"))
    s.send(username.encode("UTF-8") + b'\r\n')
    time.sleep(0.5)
    print(s.recv(4096).decode("UTF-8"))
    s.send(password.encode("UTF-8") + b'\r\n')
    time.sleep(0.5)
    print(s.recv(4096).decode("UTF-8"))

    # send = "exit\r\n"
    # s.send(send.encode("UTF-8"))

    return s

def execute(s, command):
    send = command
    s.send(send.encode("UTF-8"))
    time.sleep(0.5)
    retString = s.recv(8192).decode("UTF-8").replace(send, "")

    return retString

if __name__ == '__main__':
    HOST = 'localhost'
    PORT = 5000
    hostname = 'localhost'
    port = '23'
    username = 'onyx'
    password = '061070'
    log_count = 0
    tel_sock = 0

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((HOST, PORT))
    s.listen(1)

    conn, addr = s.accept()
    data = ""
    while 1:
        data += conn.recv(1).decode("UTF-8")
        if data.find(':quit\r\n') != -1:
            if tel_sock != 0:
                execute(tel_sock, "exit\r\n")
            break
        elif (len(re.findall(r'^host:\w*\r\n$', data)) != 0):
            hostname = data.replace('host:', '').strip()
            out = f'Hostname has been set to: {hostname}'
            data = ''
            print(out)
        elif (len(re.findall(r'^port:\w*\r\n$', data)) != 0):
            port = data.replace('port:', '').strip()
            out = f'Port has been set to: {port}'
            data = ''
            print(out)
        elif (len(re.findall(r'^username:\w*\r\n$', data)) != 0):
            username = data.replace('username:', '').strip()
            out = f'Username has been set to: {username}'
            data = ''
            print(out)
        elif (len(re.findall(r'^password:\w*\r\n$', data)) != 0):
            password = data.replace('password:', '').strip()
            out = f'Password has been set to: {password}'
            data = ''
            print(out)
        elif data.find('\r\n') != -1:
            if ((hostname == '' or port == '' or username == '' or password == '') == False):
                if tel_sock == 0:
                    tel_sock = connect(hostname, port, username, password)
                out = execute(tel_sock, data)
            else:
                out = f'One or more credentials not set.\r\n' \
                      f'Hostname: {hostname}\r\n' \
                      f'Port: {port}\r\n' \
                      f'Username: {username}\r\n' \
                      f'Password: {password}\r\n'
            data = ''
            conn.send(out.encode('UTF-8'))
        else:
            print(data)
    conn.close()