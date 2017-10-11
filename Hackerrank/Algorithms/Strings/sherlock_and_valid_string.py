import string
import sys
import copy as cp
from collections import Counter


def isValid(s):
    s = list(s)
    unique_chars = list(set(s))
    is_valid = len(set(list(Counter(s).values()))) == 1
    print(Counter(s))

    if is_valid:
        return "YES"

    for char in unique_chars:
        temp = "".join(cp.copy(s))
        temp = temp.replace(char, '', 1)

        is_valid = len(set(list(Counter(list(temp)).values()))) == 1

        if is_valid:
            return "YES"

    return "NO"

s = input().strip()
result = isValid(s)

print(result)