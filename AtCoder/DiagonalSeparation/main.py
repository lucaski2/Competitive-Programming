
from itertools import combinations

n, k = map(int, input().split())
a = list(map(int, input().split()))

# if k > n / 2, just un xor n / 2
# else normal 

full = 0
for i in range(n):
  full ^= a[i]

combs = list(combinations(range(n), n - k if k > n / 2 else k))
ans = 0
for comb in combs:
  cur = full
  for num in comb:
    cur ^= a[num]
  
  ans = max(cur, ans)
print(ans)






