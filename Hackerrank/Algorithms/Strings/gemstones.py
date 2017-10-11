#!/bin/python3

import sys

def gemstones(arr):
    unique_chars = set(list(arr[0]))

    for char in unique_chars:
        current_count = 0

        for i in range(len(arr)):
            if char in arr[i]:
                current_count += 1

        if current_count == len(arr):
            yield 1

n = int(input().strip())
arr = []
arr_i = 0
for arr_i in range(n):
   arr_t = str(input().strip())
   arr.append(arr_t)
result = gemstones(arr)
print(sum(result))
