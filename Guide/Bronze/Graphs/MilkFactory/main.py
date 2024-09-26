inp = open("factory.in", "r")
out = open("factory.out", "w")

N = int(inp.readline().strip())

pathways = [[] for _ in range(N)]

for _ in range(N - 1):
    cur_inp = list(map(int, inp.readline().strip().split()))

    pathways[cur_inp[0]].append(cur_inp[1])
    pathways[cur_inp[1]].append(cur_inp[0])




