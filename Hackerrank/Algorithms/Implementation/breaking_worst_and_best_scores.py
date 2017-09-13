import sys

def getRecord(s):
    current_min, current_max = s[0], s[0]
    count_low, count_high = 0, 0

    for i in range(1, len(s)):
        if s[i] < current_min:
            count_low += 1
            current_min = s[i]
        elif s[i] > current_max:
            count_high += 1
            current_max = s[i]

    return [count_high, count_low]

n = int(input().strip())
s = list(map(int, input().strip().split(' ')))
result = getRecord(s)
print (" ".join(map(str, result)))
