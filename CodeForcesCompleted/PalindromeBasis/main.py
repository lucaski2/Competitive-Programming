
MOD = 10**9 + 7
am = 4*10**4 + 1
palindromes = []
for i in range(1, am):
    if str(i) == str(i)[::-1]:
        palindromes.append(i)

dp = [[0] * (len(palindromes)) for _ in range(am + 1)]
dp[0][0] = 1

for i in range(0, am):
    for j in range(len(palindromes)):
        if palindromes[j] + i <= am:
            dp[i + palindromes[j]][j] = (dp[i][j] + dp[i + palindromes[j]][j]) % MOD
        if j + 1 < len(palindromes):
            dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD
for _ in range(int(input())):
    print(dp[int(input())][len(palindromes) - 1])
