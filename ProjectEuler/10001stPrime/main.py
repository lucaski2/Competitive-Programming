from math import sqrt
m = int(1e7-20)
primes = [True] * m
primes[0] = False
primes[1] = False
for i in range(2, int(sqrt(m)) + 1):
  if primes[i]:
    for j in range(i * i, m, i):
      primes[j] = False

cur = 0
for i in range(m):
  if primes[i]:
    cur += 1
  if cur == 10001:
    print(i)
    break
