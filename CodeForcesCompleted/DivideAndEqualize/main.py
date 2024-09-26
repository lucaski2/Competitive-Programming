
def get_primes(n):
    primes = []
    i = 2
    while i * i <= n:
        if n % i == 0:
            while n % i == 0:
                primes.append(i)
                n //= i
        i += 1
    if n > 1:
        primes.append(n)
    return primes


for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    divisors = {}

    for i in range(n):
        divs = get_primes(a[i])
        for d in divs:
            if d not in divisors:
                divisors[d] = 0
            divisors[d] += 1
    # print(divisors)
    for num in divisors:
        if divisors[num] % n != 0:
            print("NO")
            break
    else:
        print("YES")