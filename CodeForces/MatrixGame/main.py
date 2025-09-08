MOD = 10**9+7

def precompute_factorials(up_to):
    fact = [1]*(up_to+1)
    inv = [1]*(up_to+1)
    for i in range(1, up_to+1):
        fact[i] = fact[i-1]*i % MOD
    inv[up_to] = pow(fact[up_to], MOD-2, MOD)
    for i in range(up_to, 0, -1):
        inv[i-1] = inv[i]*i % MOD
    return fact, inv

# Suppose we have T tests and the maximum 'a' among them is A_max:
fact, inv = precompute_factorials(A_max)

for a, b, k in tests:
    # 1) compute n = k*(a-1)+1 mod
    n_full = k*(a-1) + 1
    n = n_full % MOD

    # 2) compute C(n_full, a) mod via falling product
    numer = 1
    x = n_full % MOD
    for i in range(a):
        numer = numer * ((x - i) % MOD) % MOD
    comb = numer * inv[a] % MOD

    # 3) compute m = (b-1)*k*comb + 1 mod
    m = ((b-1) % MOD) * (k % MOD) % MOD * comb % MOD
    m = (m + 1) % MOD

    print(n, m)