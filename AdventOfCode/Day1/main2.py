
a = [list(map(int, input().split())) for _ in range(1000)]
a, b = [a[i][0] for i in range(1000)], [a[i][1] for i in range(1000)]

d = {}
for i in range(1000):
  if b[i] in d:
    d[b[i]] += 1
  else:
    d[b[i]] = 1

ans = 0
for i in range(1000):
  if a[i] in d:
    ans += d[a[i]] * a[i]
print(ans)
