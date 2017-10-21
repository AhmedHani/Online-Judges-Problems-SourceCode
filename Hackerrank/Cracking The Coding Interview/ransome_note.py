from collections import Counter


def ransom_note(magazine, ransom):
    magazine_freqs = Counter(magazine)

    for word in ransom:
        if word in magazine_freqs and magazine_freqs[word] == 0:
            return False
        magazine_freqs[word] -= 1

    return True

m, n = map(int, input().strip().split(' '))
magazine = input().strip().split(' ')
ransom = input().strip().split(' ')
answer = ransom_note(magazine, ransom)
if (answer):
    print("Yes")
else:
    print("No")

