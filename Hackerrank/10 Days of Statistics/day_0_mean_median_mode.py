

import copy as cp
from collections import Counter
import math

n = int(input())
array = list(map(lambda v: float(v), str(input()).strip().split()))

sorted_array = cp.copy(array)
sorted_array.sort()

mean = sum(array) / float(len(array))
print(round(mean, 1))

median = sorted_array[len(sorted_array) // 2] if len(sorted_array) % 2 != 0 else (sorted_array[int(len(sorted_array) / 2)] + sorted_array[int(len(sorted_array) / 2) - 1]) / 2
print(round(median, 1))

freq = Counter(array)[max(Counter(array), key=Counter(array).get)]
smallest_freq_element = 1000000

for item in Counter(array).items():
    if item[1] == freq:
        smallest_freq_element = min(smallest_freq_element, item[0])

mode = smallest_freq_element
print(int(round(mode, 1)))

