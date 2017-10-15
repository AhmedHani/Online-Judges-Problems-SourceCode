import sys


line_tokens = str(input()).strip().split()
first, second, k = int(line_tokens[0]), int(line_tokens[1]), int(line_tokens[2])

print(sum([1 for i in range(first, second + 1) if (i - int(str(i)[::-1])) % k == 0]))
