#!/bin/python

import sys

def sherlockAndAnagrams(s):
    num_of_anagrams = 0

    all_substrings = []
    freqs = {}

    for i in range(0, len(s)):
        for j in range(i + 1, len(s) + 1):
            sub = ''.join(sorted(s[i:j]))

            if sub not in freqs:
                freqs[sub] = 1
            else:
                freqs[sub] += 1

    for item in freqs.items():
        num_of_anagrams += ((item[1] * (item[1] - 1))) / 2

    return num_of_anagrams

q = int(raw_input().strip())

for a0 in xrange(q):
    s = raw_input().strip()
    result = sherlockAndAnagrams(s)

    print(result)
