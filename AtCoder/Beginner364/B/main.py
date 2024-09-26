
h, w = map(int, input().split())
cur = list(map(int, input().split()))
grid = [list(input()) for _ in range(h)]
x = list(input())
cur[0] -= 1
cur[1] -= 1

for i in range(len(x)):
    if x[i] == "L":
        nex = [cur[0], cur[1] - 1]
    elif x[i] == "R":
        nex = [cur[0], cur[1] + 1]
    elif x[i] == "U":
        nex = [cur[0] - 1, cur[1]]
    else:
        nex = [cur[0] + 1, cur[1]]
    
    if not nex[0] < 0 and not nex[0] >= h and not nex[1] < 0 and not nex[1] >= w and not grid[nex[0]][nex[1]] == "#":
        cur = nex
    # print(cur)
print(cur[0] + 1, cur[1] + 1)