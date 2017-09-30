import sys


def solve(opr):
    return int(opr[0]) + int(opr[-1]) if opr[1] == '+' else int(opr[0]) - int(opr[-1])

if __name__ == "__main__":
    opr = input().strip()
    result = solve(opr)
    print(result)
