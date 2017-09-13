import sys

def timeConversion(s):
    formatted_time = ""

    line_tokens = s.strip().split(":")
    pm_or_am = line_tokens[-1][2:]

    if pm_or_am == 'AM' and int(line_tokens[0]) == 12:
        formatted_time = '00' + ":"
    elif pm_or_am == 'PM' and int(line_tokens[0]) == 12:
        formatted_time = '12' + ':'
    elif pm_or_am == 'AM' and int(line_tokens[0]) < 12:
        formatted_time = line_tokens[0] + ':'
    elif pm_or_am == 'PM' and int(line_tokens[0]) < 12:
        formatted_time = str(12 + int(line_tokens[0])) + ':'

    formatted_time += line_tokens[1] + ":"
    formatted_time += line_tokens[2][0:2]

    return formatted_time

s = input().strip()
result = timeConversion(s)
print(result)
