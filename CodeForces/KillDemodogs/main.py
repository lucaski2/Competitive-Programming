
for _ in range(int(input())):
  n = int(input())
  mod = 10**9 + 7

  s = 2*(n*(n+1)*(2*n+1) // 6) - n * (n + 1) // 2
  print(s * 2022 % mod)
