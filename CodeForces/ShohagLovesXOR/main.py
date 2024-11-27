
def num_divisors(n):
    ans = 0
    for i in range(1, n+1):
        if n % i == 0:
            ans += 1
    return ans

for i in range(1, 100):
    ans = 0
    for j in range(1, 10000):
        am = i ^ j
        if am == 0:
            continue
        if i % am == 0 or j % am == 0:
            ans += 1
    print(i, ans, num_divisors(i))
    

