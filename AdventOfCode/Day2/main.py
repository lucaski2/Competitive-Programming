n = 1000
ans = 0
a = [list(map(int, input().split())) for i in range(n)]

for i in range(n):
  if a[i] == list(sorted(a[i])) or a[i] == list(sorted(a[i], reverse=True)):
    for j in range(len(a[i]) - 1):
      diff = abs(a[i][j] - a[i][j + 1])
      if diff < 1 or diff > 3:
        break
    else:
      ans += 1

print(ans)