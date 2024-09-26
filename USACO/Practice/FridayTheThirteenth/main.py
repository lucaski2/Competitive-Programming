"""
ID: lucaski2
LANG: PYTHON3
TASK: friday
"""

inp = open("friday.in", "r")
out = open("friday.out", "w")
N = int(inp.readline().strip())
year = 1900
end_year = 1900 + N - 1
month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
weekday = 0
thirteenth = [0 for _ in range(7)]

for i in range(1900, end_year + 1):
    if i % 4 == 0 and i % 100 != 0:
        month[1] = 29
    
    elif i % 400 == 0:
        month[1] = 29

    else:
        month[1] = 28
    
    for j in range(12):
        thirteenth[(weekday + 13) % 7] += 1
        weekday += month[j]
        weekday = weekday % 7

print(thirteenth[-1], end=" ", file=out)
for i in range(6):
    if i == 5:
        print(thirteenth[i], file=out)
    else:
        print(thirteenth[i], end=" ", file=out)