
a = 1
b = 2
ans = 2
while a + b <= 4e6:
  a, b = b, a + b
  if b % 2 == 0:
    ans += b
print(ans)