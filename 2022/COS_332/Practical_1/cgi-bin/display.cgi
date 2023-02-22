#!/usr/bin/python3
import os.path
import os
from datetime import datetime
import pytz
import enum

class Zones(enum.Enum):
    Accra = 0
    Johannesburg = 2

file_path = os.path.dirname(__file__) + "/data/time_zone.txt"

if os.path.getsize(file_path) == 0:
    print(f"Content-type:text/html\r\n\r\n")
    print(f"<!DOCTYPE html>")
    print(f"<html>")
    print(f"<head>")
    print(f"<title>Test from CGI</title>")
    print(f"</head>")
    print(f"<body>")
    print(f"<h2>You are currently not in one of the specified locations. Please use the links below to travel.</h2>")
    print(f"<p><a href=\"ghana.cgi\">Go to Ghana's capital Accra</a></p>")
    print(f"<p><a href=\"rsa.cgi\">Go to South Africa's capital Johannesburg</a></p>")
    print(f"</body>")
    print(f"</html>")
else:
    infile = open(file_path, "r")

    place = infile.readline().strip()
    offset = int(infile.readline().strip())

    infile.close()

    time_zone = Zones(offset).name

    tz = pytz.timezone(f"Africa/{time_zone}")
    current_time = datetime.now(tz)

    print(f"Content-type:text/html\r\n\r\n")
    print(f"<!DOCTYPE html>")
    print(f"<html>")
    print(f"<head>")
    print(f"<title>Test from CGI</title>")
    print(f"</head>")
    print(f"<body>")
    print(f"<h2>The current time in {place} is {current_time.strftime('%I:%M:%S %p')}</h2>")
    print(f"<p><a href=\"ghana.cgi\">Go to Ghana's capital Accra</a></p>")
    print(f"<p><a href=\"rsa.cgi\">Go to South Africa's capital Johannesburg</a></p>")
    print(f"</body>")
    print(f"</html>")
