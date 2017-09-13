import sys


def custom_sort(arr, length):
    bucket = {}
    sorted_arr = []

    for num in arr:
        if len(str(num)) not in bucket:
            bucket[len(str(num))] = [str(num)]
        else:
            bucket[len(str(num))].append(str(num))

    for item in sorted(bucket):
        for value in sorted(bucket[item]):
            sorted_arr.append(value)

    return sorted_arr


n = int(input().strip())
unsorted = []

for unsorted_i in range(n):
   unsorted_t = str(input().strip())
   unsorted.append(unsorted_t)

print('\n'.join(custom_sort(unsorted, n)))
