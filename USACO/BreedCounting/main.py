inp = open("bcount.in", "r")
out = open("bcount.out", "w")
n, q = map(int, inp.readline().split())
ordering = [int(inp.readline()) for _ in range(n)]
pref = [[0, 0, 0]]
cur = [0, 0, 0]
for i in range(n):
    cur[ordering[i] - 1] += 1
    pref.append(cur.copy())

for _ in range(q):
    a, b = map(int, inp.readline().split())
    a -= 1
    
    
    print(pref[b][0] - pref[a][0], pref[b][1] - pref[a][1], pref[b][2] - pref[a][2], file=out)






