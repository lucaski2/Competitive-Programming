n, q = map(int, input().split())

x = [[0] * n for _ in range(n)]
y = [[0] * n for _ in range(n)]
z = [[0] * n for _ in range(n)]
cur_am = 0
for i in range(q):
  a, b, c = map(int, input().split())
  x[a][b] += 1
  y[b][c] += 1
  z[c][a] += 1
  if x[a][b] == n:
    cur_am += 1
  if y[b][c] == n:
    cur_am += 1
  if z[c][a] == n:
    cur_am += 1
  print(cur_am)

