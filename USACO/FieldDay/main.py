from collections import deque
c, n = map(int, input().split())

a = [int(input().replace('G', '0').replace('H', '1'), 2) for _ in range(n)]

dists = [-1] * (1 << c)

q = deque()
for i in range(n):
  q.append((a[i], 0))
  dists[a[i]] = 0

while q:
  x, dist = q.popleft()

  for i in range(c):
    y = x ^ (1 << i)
    if dists[y] == -1:
      dists[y] = dist + 1
      q.append((y, dist + 1))
  

for i in range(n):
  print(c - dists[a[i] ^ ((1 << c) - 1)])










