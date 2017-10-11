import sys


s1 = input().strip()
s2 = input().strip()
n = len(s1)
m = len(s2)

memo = [([-1] * (m + 1)) for i in range(0, n + 1)]


for i in range(0, n + 1):
    for j in range(0, m + 1):
        if i == 0 or j == 0:
            memo[i][j] = 0

        elif s1[i - 1] == s2[j - 1]:
            memo[i][j] = memo[i - 1][j - 1] + 1
        else:
            memo[i][j] = max(memo[i - 1][j], memo[i][j - 1])

print(memo[n][m])
"""
def lcs(s1, s2, n, m, memo):
    if n == 0 or m == 0:
        return 0

    if memo[n][m] != -1:
        return memo[n][m]

    if s1[n - 1] == s2[m - 1]:
        memo[n][m] = 1 + lcs(s1, s2, n - 1, m - 1, memo)

        return memo[n][m]
    else:
        memo[n][m] = max(lcs(s1, s2, n, m - 1, memo), lcs(s1, s2, n - 1, m, memo))

        return memo[n][m]

def lcs_dp(s1, s2, n, m):
    for i in range(0, n + 1):
        for j in range(0, m + 1):
            if i == 0 or j == 0:
                memo[i][j] = 0

            elif s1[i - 1] == s2[j - 1]:
                memo[i][j] = memo[i - 1][j - 1] + 1
            else:
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1])

    return memo[n][m]
def commonChild(s1, s2):
    n = len(s1)
    m = len(s2)

    for i in range(0, n + 1):
        for j in range(0, m + 1):
            if i == 0 or j == 0:
                memo[i][j] = 0

            elif s1[i - 1] == s2[j - 1]:
                memo[i][j] = memo[i - 1][j - 1] + 1
            else:
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1])

    return memo[n][m]

result = commonChild(s1, s2)


print(result)"""