
n, w = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
dp = [[0 for _ in range(w + 1)] for _ in range(n + 1)]
for i in range(n):
    for j in range(w):
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j])

        if grid[i][0] + j > w:
            continue
        dp[i + 1][j + grid[i][0]] = max(dp[i + 1][j + grid[i][0]], dp[i][j] + grid[i][1])
print(max(dp[-1]))




