n, l = map(int, input().split())
a = list(map(int, input().split()))

a.sort()
ans = 0
for i in range(n - 1, -1, -1):
  am = n - i
  for j in range(i, n):
    if a[j] >= am or l < 0:
      break
    while a[j] < am:
      a[j] += 1
      l -= 1
    
  if l < 0:
    break
  ans += 1
# print(l)
print(ans)
