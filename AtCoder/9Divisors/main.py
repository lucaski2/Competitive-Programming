import math

def solve():
    n = int(input())

    # Generate primes using the Sieve of Eratosthenes
    max_n = 10000000
    is_prime = [True] * (max_n + 25)
    is_prime[0] = is_prime[1] = False

    for i in range(2, int(math.sqrt(max_n)) + 1):
        if is_prime[i]:
            for j in range(i * i, max_n, i):
                is_prime[j] = False

    ans = 0

    # Count primes i such that i^8 <= n
    i = 2
    while i ** 8 <= n:
        if is_prime[i]:
            ans += 1
        i += 1

    # Count pairs of primes (i, j) such that i^2 * j^2 <= n
    for i in range(2, max_n + 1):
        if not is_prime[i]:
            continue
        for j in range(i + 1, max_n + 1):
            if not is_prime[j]:
                continue
            if i ** 2 * j ** 2 > n:
                break
            ans += 1

    print(ans)

if __name__ == "__main__":
    solve()