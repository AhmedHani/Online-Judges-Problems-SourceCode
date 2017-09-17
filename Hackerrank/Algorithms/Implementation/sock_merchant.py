#!/bin/python3

import sys

def sockMerchant(n, ar):
    freqs = {}

    count = 0

    for num in ar:
        if num not in freqs:
            freqs[num] = 1
        else:
            freqs[num] += 1

        if freqs[num] % 2 == 0:
            yield 1
            continue

n = int(input().strip())
ar = list(map(int, input().strip().split(' ')))
result = sockMerchant(n, ar)
print(sum(result))
