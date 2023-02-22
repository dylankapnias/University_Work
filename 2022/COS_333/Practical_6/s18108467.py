#!/usr/bin/python3
# Madam in Eden, I'm Adam.
# To run, use the command 'python3 s18108467.py "string_of_choice"' and replace string_of_choice with the string to be tested, ensuring it is encapsulated by the quotation marks.

import sys

def main(s):
    convertInput(s)

def convertInput(s):
    res = ""
    for c in s:
        if c.isalpha():
            res += c.lower()

    print(res)
    if (isPalindrome(res)):
        print("Palindrome")
    else:
        print("Not a palindrome")

def isPalindrome(s):
    if s == s[::-1]:
        return True
    else:
        return False

if __name__ == "__main__":
    main(sys.argv[1])
