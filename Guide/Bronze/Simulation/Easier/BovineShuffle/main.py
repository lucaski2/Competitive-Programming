inp = open("shuffle.in", "r")
out = open("shuffle.out", "w")
length = int(inp.readline().strip())
lst1 = list(map(int, inp.readline().strip().split()))
lst2 = list(map(int, inp.readline().strip().split()))

start = lst1.copy()

for i in range(2):
    cur = start.copy()
    for j in range(length):
        cur[j] = start[lst1[j] - 1]
    start = cur
for s in start:
    print(lst2[s - 1], file=out)




