n = int(input())
modulo = 998244353
base = 10 ** len(str(n))

print((n % modulo) * ((-n + n * pow(base, len(str(n)) * n, modulo)) * pow(base - 1, -1, modulo)) % modulo)