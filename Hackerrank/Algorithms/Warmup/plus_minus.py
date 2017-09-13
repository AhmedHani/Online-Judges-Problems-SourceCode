import sys


n = int(input().strip())
arr = [int(arr_temp) for arr_temp in input().strip().split(' ')]

plus_counter, negative_counter, zero_counter = 0, 0, 0

for num in arr:
    if num > 0:
        plus_counter += 1
    elif num == 0:
        zero_counter += 1
    else:
        negative_counter += 1

print(format(round(float(plus_counter) / float(n), 6), '.6f'))
print(format(round(float(negative_counter) / float(n), 6), '.6f'))
print(format(round(float(zero_counter) / float(n), 6), '.6f'))
