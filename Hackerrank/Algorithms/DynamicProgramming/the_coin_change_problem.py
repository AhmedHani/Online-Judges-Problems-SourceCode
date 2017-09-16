#!/bin/python3

import sys

def getWays(n, c):
    dp = [[0 for j in range(n + 1)] for i in range(len(c) + 1)]

    for i in range(len(c) + 1):
        dp[i][0] = 1

    for i in range(1, len(c) + 1):
        for j in range(1, n + 1):
            dp[i][j] = dp[i - 1][j]

            if c[i - 1] <= j:
                dp[i][j] += dp[i][j - c[i - 1]]

    return dp[len(c)][n]


n, m = input().strip().split(' ')
n, m = [int(n), int(m)]
c = list(map(int, input().strip().split(' ')))
# Print the number of ways of making change for 'n' units using coins having the values given by 'c'
ways = getWays(n, c)

print(ways)
