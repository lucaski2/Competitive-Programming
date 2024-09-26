from math import comb, perm

n = int(input())
ans = comb(n, n // 2) * (perm(n // 2, n // 2) // (n // 2)) ** 2
print(ans // 2) 


