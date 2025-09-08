def solve():
    n = int(input())
    mod = (int)(1e9 + 7)  # Assuming a common modulus

    cur = 1
    ans = 0
    while cur <= n:

          
        #what is the last element x such that n // cur == n // x
        best = n // (n // cur)


        # Compute am = sum from cur to best: (cur + best) * (best - cur + 1) / 2
        length = best - cur + 1
        total = (cur + best) % mod * length % mod
        am = total * pow(2, mod - 2, mod) % mod  # Modular inverse of 2

        ans += (n // cur) % mod * am % mod
        ans %= mod
        cur = best + 1

    print(ans)
solve();