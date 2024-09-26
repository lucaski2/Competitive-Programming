
n = int(input())
a = list(map(int, input().split()))
m = max(a) + 1
dp = [[-10000 for _ in range(m)] for _ in range(n + 1)]
dp[0][0] = 0

for i in range(n):
    for j in range(m):
        if j * 2 <= a[i]:
            dp[i + 1][a[i]] = max(dp[i + 1][a[i]], dp[i][j] + 1)
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j])

print(max(dp[-1]))
reconstruct = []
cur = dp[-1].index(max(dp[-1]))
reconstruct.append(cur)
for i in range(n, 0, -1):
    if dp[i][cur] == dp[i - 1][cur]:
        continue
    
    for j in range(cur // 2, 0, -1):
        if dp[i][cur] == dp[i - 1][j] + 1:
            reconstruct.append(j)
            cur = j
            break
print(*reversed(reconstruct))
