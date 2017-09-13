import sys

def bonAppetit(n, k, b, ar):
    return "Bon Appetit" if (sum(ar[0:k] + ar[k+1:]) / 2) == b else int(b - (sum(ar[0:k] + ar[k+1:]) / 2))

n, k = input().strip().split(' ')
n, k = [int(n), int(k)]
ar = list(map(int, input().strip().split(' ')))
b = int(input().strip())
result = bonAppetit(n, k, b, ar)
print(result)
