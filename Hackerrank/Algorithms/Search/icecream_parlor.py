import sys

def two_flavors(m, costs):
    for i in range(0, len(costs)):
        for j in range(i + 1, len(costs)):
            if costs[i] + costs[j] == m:
                return sorted([i + 1, j + 1])

T = int(input())
for i in range(0, T):
    m_dollars = int(input())
    n = int(input())
    costs = str(input()).split()
    costs = list(map(int, costs))

    print(*two_flavors(m_dollars, costs), sep=' ')
