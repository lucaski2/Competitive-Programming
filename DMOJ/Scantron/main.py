n = int(input())

s1 = list(input())
s2 = list(input())

fut = [0 for _ in range(n)]
for i in range(n - 2, -1, -1):
  fut[i] = fut[i + 1] + (s2[i] == s1[i + 1])

ans = 0
so_far = 0
for i in range(n - 1):
  ans = max(ans, so_far + fut[i])

  if s1[i] == s2[i]:
    so_far += 1
print(ans)
