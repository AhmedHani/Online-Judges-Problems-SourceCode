#!/bin/python3

import sys
import itertools


n = int(input().strip())
a = [int(a_temp) for a_temp in input().strip().split(' ')]

count = 0
pairs = list(itertools.product(a, a))

for pair in pairs:
    if abs(pair[0] - pair[1]) > 1:
        pairs.remove(pair)

print(pairs)