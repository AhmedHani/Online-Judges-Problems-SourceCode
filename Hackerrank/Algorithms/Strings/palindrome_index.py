#!/bin/python3

import sys


def __is_palindrome(s):
    return s == s[::-1]

def palindromeIndex(s):
    if __is_palindrome(s):
        return -1

    last_index = len(s) - 1

    for i in range(0, len(s)):
        if last_index - i <= i:
            break

        if s[i] != s[last_index - i]:
            if __is_palindrome(s[i:last_index-i]):
                return last_index - i
            elif __is_palindrome(s[i+1:last_index-i+1]):
                return i
            elif __is_palindrome(s[0:i] + s[i+1:]):
                return last_index - i
            elif __is_palindrome(s[0:last_index-i] + s[last_index-i+1:]):
                return last_index - i

q = int(input().strip())
for a0 in range(q):
    s = input().strip()
    result = palindromeIndex(s)
    print(result)
