from sys import stdin
import sys
from collections import Counter


def most_frequent_first(list_values):
    frequencies = Counter(list_values)
    indexes = {event: i for i, event in enumerate(list_values)}
    most_frequent_with_indexes = {indexes[key]: key for key, _ in frequencies.most_common()}

    return min(most_frequent_with_indexes.items())[1]


lines = sys.stdin.read().lower().split(".")
trigrams = []
idx = 0
tri_to_idx = {}
idx_to_tri = {}

for line in lines:
    line_tokens = line.strip().rstrip().split()

    for i in range(0, len(line_tokens)):
        trigram = ""

        if i + 1 <= len(line_tokens) - 1 and i + 2 <= len(line_tokens) - 1:
            trigram += line_tokens[i] + " " + line_tokens[i + 1] + " " + line_tokens[i + 2]

            if trigram not in tri_to_idx:
                tri_to_idx[trigram] = idx
                idx_to_tri[idx] = trigram
                idx += 1

            trigrams.append(trigram)

freqs = Counter(trigrams)

max_freq = -1

for item in freqs.items():
    max_freq = max(max_freq, item[1])

candidates = []

for item in freqs.items():
    if item[1] == max_freq:
        candidates.append(item[0])

target_idx = 1 << 25

for can in candidates:
    if tri_to_idx[can] < target_idx:
        target_idx = tri_to_idx[can]

print(idx_to_tri[target_idx])
