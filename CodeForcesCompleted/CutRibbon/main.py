
a = list(map(int, input().split()))
n = a[0]
a = a[1:]
dp = [0] * (n + 1)
dp[n] = 1
for i in range(n, 0, -1):
    if dp[i] >= 1:
        for j in a:
            if i - j >= 0:
                dp[i - j] = max(dp[i - j], dp[i] + 1)
    # print(dp)
print(dp[0] - 1)