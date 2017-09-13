import sys

def migratoryBirds(n, ar):
    freqs_array = [0] * 6
    max_freq = -1

    for num in ar:
        freqs_array[num] += 1
        max_freq = max(max_freq, freqs_array[num])

    for i in range(1, len(freqs_array)):
        if freqs_array[i] == max_freq:
            return i


n = int(input().strip())
ar = list(map(int, input().strip().split(' ')))
result = migratoryBirds(n, ar)
print(result)
