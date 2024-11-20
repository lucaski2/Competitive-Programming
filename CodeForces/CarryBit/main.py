
n, k = map(int, input().split())

mod = 10 ** 9 + 7


dp = [[[0, 0] for _ in range(k)] for _ in range(n)]

dp[0][0][0] = 1



