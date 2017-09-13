import sys


def kangaroo(x1, v1, x2, v2):
    prev_diff = abs(x1 - x2)

    if x1 >= x2:
        while True:
            if x1 == x2:
                return "YES"

            if x2 > x1:
                return "NO"

            x1 += v1
            x2 += v2

            if prev_diff <= abs(x1 - x2):
                return "NO"
    else:
        while True:
            if x1 == x2:
                return "YES"

            if x2 < x1:
                return "NO"

            x1 += v1
            x2 += v2

            if prev_diff <= abs(x1 - x2):
                return "NO"

x1, v1, x2, v2 = input().strip().split(' ')
x1, v1, x2, v2 = [int(x1), int(v1), int(x2), int(v2)]
result = kangaroo(x1, v1, x2, v2)
print(result)
