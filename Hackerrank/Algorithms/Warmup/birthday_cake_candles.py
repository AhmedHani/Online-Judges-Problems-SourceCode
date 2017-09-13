import sys


def birthdayCakeCandles(n, ar):
    tallest_candles = -10000000

    for num in ar:
        tallest_candles = max(tallest_candles, num)

    return sum([1 for i, candle in enumerate(ar) if candle == tallest_candles])


n = int(input().strip())
ar = list(map(int, input().strip().split(' ')))
result = birthdayCakeCandles(n, ar)
print(result)
