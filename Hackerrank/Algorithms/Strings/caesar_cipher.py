#!/bin/python3

import sys


n = int(input().strip())
s = input().strip()
k = int(input().strip())

output = ""
for i in range(0, len(s)):
    if s[i].isalpha():
        if s[i].islower():
            output += chr(ord('a') + ((ord(s[i]) + k - ord('a')) % 26))
        else:
            output += chr(ord('A') + ((ord(s[i]) + k - ord('A')) % 26))
    else:
        output += s[i]

print(output)