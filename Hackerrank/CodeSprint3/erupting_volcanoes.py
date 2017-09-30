#!/bin/python3

import sys
import numpy as np

done = [False, False, False, False, False, False]


def flood_fill(i, j, value, volcano_map, state, ori_i, ori_j):
    if i >= len(volcano_map) or j >= len(volcano_map[0]):
        return

    elif i < 0 or j < 0:
        return
    else:
        value = max(0, value)
        if i == ori_i and j == ori_j:
            volcano_map[i][j] = value
        else:
            volcano_map[i][j] += value

    if state == 0:
        flood_fill(i + 1, j, value - 1, volcano_map, state, ori_i, ori_j)
    if state == 1:
        flood_fill(i, j + 1, value - 1, volcano_map, state, ori_i, ori_j)
    if state == 2:
        flood_fill(i + 1, j + 1, value - 1, volcano_map, state, ori_i, ori_j)
    if state == 3:
        flood_fill(i - 1, j, value - 1, volcano_map, state, ori_i, ori_j)
    if state == 4:
        flood_fill(i, j - 1, value - 1, volcano_map, state, ori_i, ori_j)
    if state == 5:
        flood_fill(i - 1, j - 1, value - 1, volcano_map, state, ori_i, ori_j)
    if state == 6:
        flood_fill(i + 1, j - 1, value - 1, volcano_map, state, ori_i, ori_j)
    if state == 7:
        flood_fill(i - 1, j + 1, value - 1, volcano_map, state, ori_i, ori_j)

if __name__ == "__main__":
    n = int(input().strip())
    m = int(input().strip())
    volcano_map = [[0 for j in range(n)] for i in range(n)]
    for a0 in range(m):
        x, y, w = input().strip().split(' ')
        x, y, w = [int(x), int(y), int(w)]

        volcano_map[x][y] = w

        for i in range(0, 8):
            flood_fill(x, y, w, volcano_map, i, x, y)
    print(max(map(max, volcano_map)))
        #exit()
