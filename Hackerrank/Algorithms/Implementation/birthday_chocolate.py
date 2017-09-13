import sys

def solve(n, s, d, m):
    count_ways = 0
    squares_sum = 0

    for i in range(0, n):
        squares_sum += 1
        current_sum = s[i]

        if squares_sum == m:
            if current_sum == d:
                count_ways += 1
                squares_sum = 0
                continue

        for j in range(1, m):

            if i + j <= n - 1:
                current_sum += s[i + j]

        if current_sum == d:
            count_ways += 1

    return count_ways

n = int(input().strip())
s = list(map(int, input().strip().split(' ')))
d, m = input().strip().split(' ')
d, m = [int(d), int(m)]
result = solve(n, s, d, m)
print(result)
