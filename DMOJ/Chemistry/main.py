n, m = map(int, input().split())
if n == 1 and m == 1:
  print(1)
  print(1)
elif n == 1:
  print(2)
  for i in range(m):
    print(i % 2 + 1, end = " ")
  print()
elif m == 1:
  print(2)
  for i in range(n):
    print(i % 2 + 1)

else:
  print(4)
  for i in range(n):
    for j in range(m):
      print((i % 2) * 2 + j % 2 + 1, end = " ")
    print()