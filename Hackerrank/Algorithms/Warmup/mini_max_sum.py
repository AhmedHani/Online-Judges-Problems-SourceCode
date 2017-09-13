import sys

arr = list(map(int, input().strip().split(' ')))

minimum_maximum = [1000000000 * len(arr), -1000000000 * len(arr)]

for it in range(len(arr)):
    current_sum = sum([element for i, element in enumerate(arr) if i != it])
    minimum_maximum[0] = min(minimum_maximum[0], current_sum)
    minimum_maximum[1] = max(minimum_maximum[1], current_sum)

print(str(minimum_maximum[0]) + " " + str(minimum_maximum[1]))
