#!/bin/python3

import sys

def solve(n, p):
    #all_pages = ((n + 2) / 2)
    #begin = ((p + 2) / 2) - 1
    #end = all_pages - begin - 1

    return min(p / 2, (n / 2) - (p / 2))


n = int(input().strip())
p = int(input().strip())
result = solve(n, p)
print(result)
