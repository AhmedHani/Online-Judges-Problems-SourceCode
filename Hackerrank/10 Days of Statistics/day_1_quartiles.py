import copy as cp

n = int(input())
array = list(map(int, str(input()).split()))

sorted_array = cp.copy(array)
sorted_array.sort()

if len(sorted_array) % 2 != 0:
    q2 = sorted_array[len(sorted_array) // 2]
    q1_half = sorted_array[0:len(sorted_array) // 2]
    q3_half = sorted_array[(len(sorted_array) // 2) + 1:]

    print((q1_half[len(q1_half) // 2] + q1_half[(len(q1_half) // 2) - 1]) // 2)
    print(q2)
    print((q3_half[len(q3_half) // 2] + q3_half[(len(q3_half) // 2) - 1]) // 2)
else:
    q2 = (sorted_array[len(sorted_array) // 2] + sorted_array[(len(sorted_array) // 2) - 1]) // 2
    q1_half = sorted_array[0:(len(sorted_array) // 2) - 1]
    q3_half = sorted_array[(len(sorted_array) // 2) + 1:]

    print((q1_half[len(q1_half) // 2] + q1_half[(len(q1_half) // 2) - 1]) // 2)
    print(q2)
    print((q3_half[len(q3_half) // 2] + q3_half[(len(q3_half) // 2) - 1]) // 2)