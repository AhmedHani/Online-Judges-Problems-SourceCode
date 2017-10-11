#!/bin/python3

import sys

def alternatingCharacters(s):
    return sum([1 for i in range(0, len(s) - 1) if s[i] == s[i + 1]])

q = int(input().strip())
for a0 in range(q):
    s = input().strip()
    result = alternatingCharacters(s)
    print(result)
