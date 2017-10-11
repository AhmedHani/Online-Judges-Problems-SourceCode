#!/bin/python3

import sys

def minSteps(n, B):
    B = list(B)

    for i in range(2, len(B)):
        if ''.join(B[i-2:i+1]) == '010':
            B[i] = '1'
            yield 1

n = int(input().strip())
B = input().strip()
result = minSteps(n, B)
print(sum(list(result)))
