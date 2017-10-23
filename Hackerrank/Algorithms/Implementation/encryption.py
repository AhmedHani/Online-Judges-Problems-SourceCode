#!/bin/python3

import sys
import math


s = input().strip()
sentence_length = len(s)
rows, columns = int(math.floor(math.sqrt(sentence_length))), int(math.ceil(math.sqrt(sentence_length)))

if rows * columns < sentence_length:
    rows += 1
    if rows * columns < sentence_length:
        columns += 1

assert rows * columns >= sentence_length

grid = [[None] * columns for i in range(rows)]
idx = 0

for i in range(0, rows):
    if idx == len(s):
        break

    for j in range(0, columns):
        if idx == len(s):
            break
        grid[i][j] = s[idx]
        idx += 1

result = ""

for j in range(0, columns):
    word = ""

    for i in range(0, rows):
        if grid[i][j] is None:
            continue

        word += grid[i][j]

    result += word + " "

print(result[0:-1])

