def array_left_rotation(a, n, k):
    rotated = [None] * n

    for i in range(0, n):
        rotated[(n + i - k) % n] = a[i]

    return rotated


n, k = map(int, input().strip().split(' '))
a = list(map(int, input().strip().split(' ')))
answer = array_left_rotation(a, n, k)
print(*answer, sep=' ')
