N, M = list(map(int, input().split()))
lines = []
for i in range(N):
    lines.append(input())
moves = 1
for j in range(M):
    line = ""
    for i in range(N):
        line += lines[i][j]
    if "$" not in line:
        moves += 1
print(moves)