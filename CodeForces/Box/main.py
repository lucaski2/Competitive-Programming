
for _ in range(int(input())):
  n = int(input())
  a = list(map(int, input().split()))

  ans = [0] * n
  not_used = set(range(1, n+1))

  for i in range(n):
    if i == 0 or a[i] != a[i-1]:
      ans[i] = a[i]
      not_used.remove(a[i])
  
  not_used = list(not_used)
  not_used.sort(reverse=True)
  for i in range(n):
    if ans[i] == 0:
      ans[i] = not_used.pop()
  
  for i in range(n):
    if ans[i] > a[i]:
      print(-1)
      break
  else:
    print(*ans) 