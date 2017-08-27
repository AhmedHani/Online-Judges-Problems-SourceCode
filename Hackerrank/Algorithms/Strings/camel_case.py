___author__ = 'Ahmed Hani Ibrahim'

line = str(input()).strip()

print(sum(c.isupper() for c in line) + 1)
