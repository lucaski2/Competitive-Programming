inp = open("socdist2.in", 'r')
out = open("socdist2.out", 'w')

n = int(inp.readline())

cows = sorted([list(map(int, inp.readline().strip().split())) for _ in range(n)], key=lambda x: x[0])


for i in range(n):
    if cows[i][1] == 0:
        break
else:
    print(1, file=out)

max_gap = 1000000

for i in range(n):
    if i != 0 and cows[i - 1][1] == 0 and cows[i][1] != 0:
        if cows[i][0] - cows[i - 1][0] < max_gap:
            max_gap = cows[i][0] - cows[i - 1][0]
    
    if i != n - 1 and cows[i + 1][1] == 0 and cows[i][1] != 0:
        if cows[i + 1][0] - cows[i][0] < max_gap:
            max_gap = cows[i + 1][0] - cows[i][0]


cnt = 1

for i in range(n):
    if i != n - 1 and cows[i][1] == 1 and cows[i + 1][1] == 1:
        if cows[i + 1][0] - cows[i][0] >= max_gap:
            cnt += 1
    
    if i != n - 1 and i != 0 and cows[i][1] == 1 and cows[i - 1][1] == 0 and cows[i + 1][1] == 0:
        cnt += 1

    if i == n - 1 and cows[i][1] == 1 and cows[i - 1][1] == 0:
        cnt += 1
    

print(cnt, file=out)






