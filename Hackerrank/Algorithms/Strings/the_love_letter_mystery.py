#!/bin/python3

import sys

def __is_palindrome(s):
    return s == s[::-1]

def theLoveLetterMystery(s):
    if __is_palindrome(s):
        return 0

    last_index = len(s) - 1
    count = 0

    for i in range(0, len(s)):
        if last_index - i <= i:
            break
        if s[i] != s[last_index - i]:
            count += abs(ord(s[i]) - ord(s[last_index - i]))

    return count


q = int(input().strip())
for a0 in range(q):
    s = input().strip()
    result = theLoveLetterMystery(s)
    print(result)
