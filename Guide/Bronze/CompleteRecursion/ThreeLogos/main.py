inp = list(map(int, input().split()))
dims = [(inp[i], inp[i + 1]) for i in range(0, 6, 2)]

s = 0
for i in range(len(dims)):
    s += dims[i][0] * dims[i][1]
if s != 25:
    print(-1)




