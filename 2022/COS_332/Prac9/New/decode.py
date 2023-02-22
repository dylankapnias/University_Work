#!/usr/bin/env python3
# # \xff\xfb\x1f\xff\xfb \xff\xfb\x18\xff\xfb'\xff\xfd\x01\xff\xfb\x03\xff\xfd\x03
# data = b'fffb1ffffbfffb18fffbfffd01fffb03fffd03'
# data = b'\xff\xfd\x1f\xff\xfb\x01\xff\xfd\x03\xff\xfb\x03'
# for i in range(0, len(data), 2):
#     print(int(data[i:i+2], 16))

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

# def stripPS(sline:str):
#     array = sline.split()
#
#     for p in array:
#         if p == "ps":
#             array.remove(p)
#
#     retString = " ".join(array)
#
#     return retString

if __name__ == "__main__":
    print(stripPS("liam\r\n"))
    print(stripPS("l19am2992\r\n"))