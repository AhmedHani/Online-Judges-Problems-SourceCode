#!/bin/python3

import sys

def stringConstruction(s):
    visited = set()
    constructed = ""
    counter = 0

    for char in s:
        if char not in visited:
            visited.add(char)
            counter += 1
            constructed += char
        else:
            constructed += char

    return counter

if __name__ == "__main__":
    q = int(input().strip())
    for a0 in range(q):
        s = input().strip()
        result = stringConstruction(s)
        print(result)
