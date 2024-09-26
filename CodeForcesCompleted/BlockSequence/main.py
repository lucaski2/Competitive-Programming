
def get(dp, i, n):
    if i > n:
        return float('inf')
    if i == n:
        return 0
    return dp[i]

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    dp = [float('inf')] * n
    dp[-1] = 1
    
    for i in range(n-2, -1, -1):
        dp[i] = min(dp[i + 1] + 1, get(dp, i + a[i] + 1, n))
    print(dp[0])