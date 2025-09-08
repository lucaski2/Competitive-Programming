
n = 1
for i in range(1, 101):
  n *= i

s = 0
n = str(n)

for c in n:
  s += int(c)
print(s)