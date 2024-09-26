
n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]
# grid = [[g[i][j] for i in range(len(g))] for j in range(len(g[0]))]
dp = [[0 for _ in range(3)] for _ in range(n + 1)]
# print(grid)
for i in range(n):
    for j in range(3):
        others = [k for k in range(3) if k != j]
        for k in others:
            dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + grid[i][k])
    

# for d in dp:
#     print(*d)
print(max(dp[n]))










