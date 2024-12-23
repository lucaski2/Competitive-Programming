from math import ceil
avg = int(input())
a = int(input())

# (avg * a + x) / (a + 1) = 80
# x = 80(a + 1) - avg * a
ans = 80 * (a + 1) - avg * a
if ans <= 100:
  print(max(0, ceil(ans)))
else: 
  print(-1)