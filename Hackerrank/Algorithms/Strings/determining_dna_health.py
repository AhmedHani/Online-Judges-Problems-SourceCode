#!/bin/python3

import sys


n = int(input().strip())
genes = input().strip().split(' ')
health = list(map(int, input().strip().split(' ')))
s = int(input().strip())

min_health, max_health = (1 << 25), -( 1 << 25)

genes_dict = {}

for i in range(0, len(genes)):
    genes_dict[i] = (genes[i], health[i])

for a0 in range(s):
    first,last,d = input().strip().split(' ')
    first,last,d = [int(first),int(last),str(d)]

    current_string = d


