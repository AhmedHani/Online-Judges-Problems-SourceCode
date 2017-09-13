import sys

def getTotalX(a, b):
    count_numbers = 0

    for i in range(1, 101):
        current_number = i
        ignore = False

        for a_element in a:
            if current_number % a_element != 0:
                ignore = True
                break

        for b_element in b:
            if b_element % current_number != 0:
                ignore = True
                break

        if not ignore:
            count_numbers += 1

    return count_numbers


if __name__ == "__main__":
    n, m = input().strip().split(' ')
    n, m = [int(n), int(m)]
    a = list(map(int, input().strip().split(' ')))
    b = list(map(int, input().strip().split(' ')))
    total = getTotalX(a, b)
    print(total)
