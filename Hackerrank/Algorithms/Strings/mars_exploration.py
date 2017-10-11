import sys


S = input().strip()

target_message = ''.join(['SOS'] * int(len(S) / 3))
print(sum([1 for i in range(0, len(target_message)) if target_message[i] != S[i]]))