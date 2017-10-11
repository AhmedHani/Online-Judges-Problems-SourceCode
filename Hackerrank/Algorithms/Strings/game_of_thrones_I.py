#!/bin/python3

import sys
from collections import Counter


def gameOfThrones(s):
    freqs = Counter(s)

    if len(s) % 2 != 0:
        one_odd = 0

        for item in freqs.items():
            if item[1] % 2 != 0:
                one_odd += 1

        return "YES" if one_odd == 1 else "NO"
    else:
        for item in freqs.items():
            if item[1] % 2 != 0:
                return "NO"

        return "YES"


s = input().strip()
result = gameOfThrones(s)
print(result)
