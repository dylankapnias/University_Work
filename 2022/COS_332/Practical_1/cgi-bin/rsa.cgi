#!/usr/bin/python3

import os.path

outfile = open(os.path.dirname(__file__) + "/data/time_zone.txt", "w")

outfile.write("South Africa, Johannesburg\n")
outfile.write("2")

outfile.close()

print(f"Content-type:text/html\r\n\r\n")
print(f"<!DOCTYPE html>")
print(f"<html>")
print(f"<head>")
print(f"<title>Arrived at Johannesburg</title>")
print(f"</head>")
print(f"<body>")
print(f"<p>You have arrived at Johannesburg</p>")
print(f"<a href=\"display.cgi\">Would you like to view the current time?</a>")
print(f"</body>")
print(f"</html>")
