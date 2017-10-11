#!/bin/python3

import sys
from collections import Counter

def anagram(s):
    if len(s) % 2 != 0:
        return -1

    alpha = s[0:(len(s)//2)]
    beta = s[(len(s)//2):]

    beta = Counter(beta)

    for char in alpha:
        if char in beta:
            beta[char] -= 1

    return sum([item[1] for item in beta.items() if item[1] >= 0])

q = int(input().strip())
for a0 in range(q):
    s = input().strip()
    result = anagram(s)
    print(result)
