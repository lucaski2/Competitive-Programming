
a, b, n = map(int, input().split())
a *= 10
for i in range(10):
  a += i
  if a % b == 0:
    print(str(a) + (n - 1) * '0')
    break
  a -= i
else:
  print(-1)
