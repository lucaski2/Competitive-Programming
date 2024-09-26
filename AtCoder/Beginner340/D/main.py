
n = int(input())
stages = [list(map(int, input().split())) for _ in range(n - 1)]
for i in range(n - 1):
    stages[i][2] -= 1

dp = [float('inf') for _ in range(n)]
dp[0] = 0
for _ in range(100):
    for i in range(n - 1):
        dp[i + 1] = min(dp[i + 1], dp[i] + stages[i][0])
        dp[stages[i][2]] = min(dp[stages[i][2]], dp[i] + stages[i][1])
print(dp[n - 1])








