
def get_prime_factors(n):
    ret = []
    num = 2
    while num * num <= n:
        if n % num == 0:
            return num
        num += 1
    return n
    



n = int(input())
lst = [i + 2 for i in range(n - 1)]
prime_factors = set()
for i in range(n - 1):
    lst[i] = get_prime_factors(lst[i])
    prime_factors.add(lst[i])

prime_factors = list(prime_factors)
prime_factors.sort()
primes = {}

for i in range(len(prime_factors)):
    primes[prime_factors[i]] = i + 1


for i in range(n - 1):
    lst[i] = primes[lst[i]]


print(*lst)


