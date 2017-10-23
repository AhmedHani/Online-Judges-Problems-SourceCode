
n = int(input())
array = list(map(lambda v: float(v), str(input()).strip().split()))
weights = list(map(lambda v: int(v), str(input()).strip().split()))

print(round(sum([item[0] * item[1] for item in zip(array, weights)]) / sum(weights), 1))


