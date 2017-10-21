from collections import Counter


def number_needed(a, b):
    s1_freq = Counter(a)
    s2_freq = Counter(b)

    counter = 0
    for item in s2_freq.items():
        if item[0] in s1_freq:
            counter += max(0, s2_freq[item[0]] - s1_freq[item[0]])
        else:
            counter += item[1]

    for item in s1_freq.items():
        if item[0] in s2_freq:
            counter += max(0, s1_freq[item[0]] - s2_freq[item[0]])
        else:
            counter += item[1]

    return counter

a = input().strip()
b = input().strip()

print(number_needed(a, b))
