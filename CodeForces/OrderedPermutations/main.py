from itertools import permutations

n = 7
perms = list(permutations(range(1, n+1)))
m = 0
for perm in perms:
  s = 0
  for i in range(n):
    for j in range(i + 1, n + 1):
      s += min(perm[i:j])
  m = max(m, s)
print(m)
for perm in perms:
  s = 0
  for i in range(n):
    for j in range(i + 1, n + 1):
      s += min(perm[i:j])
  
  if s == m:
    print(*perm)

