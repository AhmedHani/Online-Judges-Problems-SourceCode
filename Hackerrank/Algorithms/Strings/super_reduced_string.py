#!/bin/python3

import sys


def super_reduced_string(s):
    i = 1

    while i < len(s):
        if s[i] == s[i - 1]:
            l = list(s)
            del l[i]
            del l[i - 1]
            s = ''.join(l)
            i = 0
        else:
            i += 1

    return s if s else "Empty String"

s = input().strip()
result = super_reduced_string(s)
print(result)
