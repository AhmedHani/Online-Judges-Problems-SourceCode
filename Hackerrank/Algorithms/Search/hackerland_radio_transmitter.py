#!/bin/python3

import sys


def transmitter_count(x, k):
    if len(x) == 1 or len(x) == 2 or len(x) == 3:
        return 1

    sorted_houses = sorted(x)
    count = 0
    i = 0

    while i < len(sorted_houses):
        count += 1
        pivot = sorted_houses[i] + k

        while i < len(x) and sorted_houses[i] <= pivot:
            i += 1
        i -= 1
        pivot = sorted_houses[i] + k
        while i < len(x) and sorted_houses[i] <= pivot:
            i += 1

    return count

n,k = input().strip().split(' ')
n,k = [int(n),int(k)]
x = [int(x_temp) for x_temp in input().strip().split(' ')]

print(transmitter_count(x, k))



