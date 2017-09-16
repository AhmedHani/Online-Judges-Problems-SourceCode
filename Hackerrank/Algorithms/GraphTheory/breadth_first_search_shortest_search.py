#!/bin/python3

import sys

if __name__ == "__main__":
    q = int(input().strip())
    for a0 in range(q):
        n, m = input().strip().split(' ')
        n, m = [int(n), int(m)]
        adj_list = [[0 for j in range(n + 1)] for i in range(n + 1)]

        for a1 in range(m):
            u, v = input().strip().split(' ')
            u, v = [int(u), int(v)]
            adj_list[u].append(v)

        s = int(input().strip())

        edge_weight = 6

        distance = [-1] * (n + 1)
        distance[s] = 0

        queue = [s]
        visited = set()
        visited.add(s)

        while len(queue) != 0:
            current_node = queue.pop(0)

            for i in range(0, len(adj_list[current_node])):
                next_node = adj_list[current_node][i]

                if next_node not in visited:
                    visited.add(next_node)
                    distance[next_node] = distance[current_node] + 6
                    queue.append(next_node)

        res = ""

        for i in range(1, len(distance)):
            if i != s:
                res += str(distance[i]) + " "

        print(res)
