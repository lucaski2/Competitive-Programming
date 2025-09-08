from math import pow

s = int(pow(2, 1000))

ans = 0

while s > 0:
  ans += s % 10
  s //= 10
print(ans)

