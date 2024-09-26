
MOD = 10 ** 9 + 7
n = int(input())
factorials = [1] * (n + 1)
for i in range(1, n + 1):
    factorials[i] = factorials[i - 1] * i
    factorials[i] %= MOD

factorial_inverses  = [1] * (n + 1)
for i in range(1, n + 1):
    factorial_inverses[i] = pow(factorials[i], MOD - 2, MOD)

ans = 0
for i in range(n + 1):
    ans += factorials[n] * factorial_inverses[i] * factorial_inverses[n - i]
    ans %= MOD
print(ans)

