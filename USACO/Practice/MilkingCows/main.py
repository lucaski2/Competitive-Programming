"""
ID: lucaski2
TASK: milk2
LANG: PYTHON3
"""

inp = open('milk2.in','r')
out = open('milk2.out', 'w')
N = int(inp.readline().strip())
lines = [tuple(map(int, inp.readline().strip().split())) for _ in range(N)]

lines.sort(key=lambda x: x[0])
longest = 0
cur_end = 0
cur_time = 0
streak = 0
longest_without = 0
for i in range(N):

    if lines[i][0] > cur_end:
        streak += cur_end - cur_time
        if streak > longest:
            longest = streak
        cur_long_without = lines[i][0] - cur_end 
        if cur_long_without > longest_without:
            longest_without = cur_long_without

        streak = 0
    if cur_end < lines[i][1]:
        cur_end = lines[i][1]
    if lines[i][0] > cur_time and not lines[i][0] > cur_end:
        if i != 0:
            streak += lines[i][0] - cur_time
        cur_time = lines[i][0]
        
    if streak > longest:
        longest = streak
    




    print("cur time", cur_time, "cur end", cur_end, "streak", streak, "longest", longest)

if len(lines) == 1:
    print(str(lines[0][1] - lines[0][0]) + " " + str(0), file=out)
else:
    print(str(longest) + " " + str(longest_without), file=out)
