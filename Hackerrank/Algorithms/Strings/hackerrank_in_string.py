#!/bin/python3

import sys


def lcs_dp(alpha_string, beta_string):
    dp_table = [[0 for j in range(0, len(beta_string) + 1)] for i in range(0, len(alpha_string) + 1)]

    for i in range(1, len(alpha_string) + 1):
        for j in range(1, len(beta_string) + 1):
            if alpha_string[i - 1] == beta_string[j - 1]:
                dp_table[i][j] = dp_table[i - 1][j - 1] + 1
            else:
                dp_table[i][j] = max(dp_table[i - 1][j], dp_table[i][j - 1])

    # print(dp_table[self.__alpha_string_length][self.__beta_string_length])

    lcs_string = ""
    alpha_ptr = len(alpha_string)
    beta_ptr = len(beta_string)

    while alpha_ptr != 0 and beta_ptr != 0:
        if dp_table[alpha_ptr][beta_ptr] == dp_table[alpha_ptr][beta_ptr - 1]:
            beta_ptr -= 1
        elif dp_table[alpha_ptr][beta_ptr] == dp_table[alpha_ptr - 1][beta_ptr]:
            alpha_ptr -= 1
        else:
            lcs_string += alpha_string[alpha_ptr - 1]
            alpha_ptr -= 1
            beta_ptr -= 1

    return lcs_string[::-1]


q = int(input().strip())
for a0 in range(q):
    s = input().strip()

    print("YES" if lcs_dp(s, "hackerrank") == "hackerrank" else "NO")


