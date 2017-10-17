import sys
from collections import Counter

def missing_numbers(a, b):
    a_freqs, b_freqs = Counter(a), Counter(b)

    for item in b_freqs.items():
        if item[0] in a_freqs:
            if a_freqs[item[0]] == item[1]:
                continue
            else:
                yield item[0]
        else:
            yield item[0]


n = int(input())
a = list(map(int, str(input()).split()))
m = int(input())
b = list(map(int, str(input()).split()))

print(*sorted(list(missing_numbers(a, b))), sep=' ')




