import sys


n = int(input().strip())

for i in range(1, n + 1):
    line = ""

    for j in range(0, n):
        if i - j > 0:
            line += '#'
        else:
            line += " "

    print(line[::-1])
