
print("pangram" if len(set(list(str(input()).replace(" ", "").lower()))) == 26 else "not pangram")