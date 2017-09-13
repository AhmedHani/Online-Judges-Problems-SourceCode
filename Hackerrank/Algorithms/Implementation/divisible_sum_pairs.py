import sys
import itertools
import time


def divisibleSumPairs(n, k, ar):
    return sum([1 for pair in itertools.combinations(ar, 2) if sum(pair) % k == 0])

n, k = input().strip().split(' ')
n, k = [int(n), int(k)]
ar = list(map(int, input().strip().split(' ')))
start_time = time.clock()
result = divisibleSumPairs(n, k, ar)
print("--- %s seconds ---" % (time.clock() - start_time))
print(result)
