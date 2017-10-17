#!/bin/python3

import sys

def solve(a):
    if len(a) == 1:
        return "YES"

    after_sum = sum(a[1:])
    before_sum = 0

    for i in range(0, len(a) - 1):
        if before_sum == after_sum:
            return "YES"

        before_sum += a[i]
        after_sum -= a[i+1]

    return "NO"


T = int(input().strip())
for a0 in range(T):
    n = int(input().strip())
    a = list(map(int, input().strip().split(' ')))
    result = solve(a)
    print(result)
