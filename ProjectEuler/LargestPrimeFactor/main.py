from math import sqrt
n = 600851475143
ans = 0
for i in range(2, int(sqrt(n)) + 1):
  while n % i == 0:
    ans = max(ans, i)
    n //= i

print(max(ans, n))
