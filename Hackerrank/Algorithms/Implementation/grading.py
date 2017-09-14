import sys

def solve(grades):
    for grade in grades:
        for i in range(grade, 101):
            if i % 5 == 0:
                if i - grade < 3:
                    if i < 40:
                        yield grade
                    else:
                        yield i
                    break
                else:
                    yield grade
                    break

n = int(input().strip())
grades = []

for grades_i in range(n):
   grades_t = int(input().strip())
   grades.append(grades_t)
result = solve(grades)
print("\n".join(map(str, result)))
