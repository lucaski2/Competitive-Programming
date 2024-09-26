MOD = 10**9 + 7

def mod_inverse(x, mod):
    return pow(x, mod - 2, mod)

def solve():
    t = int(input())
    results = []
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))

        sum_a = sum(a)
        sum_a2 = sum(x * x for x in a)
        
        P = (sum_a * sum_a - sum_a2) // 2
        Q = n * (n - 1) // 2
        
        Q_inv = mod_inverse(Q, MOD)
        result = (P * Q_inv) % MOD
        results.append(result)
    
    print("\n".join(map(str, results)))

