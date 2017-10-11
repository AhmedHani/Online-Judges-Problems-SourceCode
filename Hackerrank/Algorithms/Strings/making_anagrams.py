#!/bin/python3

import sys
from collections import Counter

def makingAnagrams(s1, s2):
    s1_freq = Counter(s1)
    s2_freq = Counter(s2)

    counter = 0
    for item in s2_freq.items():
        if item[0] in s1_freq:
            counter += max(0, s2_freq[item[0]] - s1_freq[item[0]])
        else:
            counter += item[1]

    for item in s1_freq.items():
        if item[0] in s2_freq:
            counter += max(0, s1_freq[item[0]] - s2_freq[item[0]])
        else:
            counter += item[1]

    return counter

s1 = input().strip()
s2 = input().strip()
result = makingAnagrams(s1, s2)
print(result)
