inp = open("hps.in", 'r')
out = open("hps.out", 'w')

n = int(inp.readline())
games = [inp.readline().strip() for _ in range(n)]

psum = [[0, 0, 0]]
cur = [0, 0, 0]
for game in range(n):
    if games[game] == "H":
        cur[0] += 1
    elif games[game] == "P":
        cur[1] += 1
    else:
        cur[2] += 1
    
    psum.append(cur.copy())

# print(psum)
ans = 0
for i in range(n):
    for j in range(3):
        for k in range(3):
            ans = max(ans, psum[i][j] + (psum[n][k] - psum[i][k]))

print(ans, file=out)
