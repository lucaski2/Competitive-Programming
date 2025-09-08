import sys

MOD = 645305806994953711

def mod_inv(a, m=MOD):
    return int(pow(a, m - 2, m))

def mod_pow(a, b, m=MOD):
    ans = 1
    while b:
        if b & 1:
            ans = (ans * a) % m
        b //= 2
        a = (a * a) % m
    return ans

def factorial(n):
    ans = 1
    for i in range(1, n + 1):
        ans = (ans * i) % MOD
    return ans

def choose(n, k):
    if k > n:
        return 0
    return (factorial(n) * mod_inv(factorial(k)) % MOD * mod_inv(factorial(n - k)) % MOD) % MOD


def solve():
    n, k = map(int, input().split())
    ans = 1
    d = [0, 1, 2, 9]
    
    for i in range(1, k + 1):
        am = d[i - 1]
        ans += choose(n, i) * am
    
    print(ans)

solve()