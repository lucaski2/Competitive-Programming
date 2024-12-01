
n = int(input())
s = list(input())
s2 = list(input())

ans = 0

last = -1
for i in range(n):
  if s[i] != s2[i]:
    last = i
  else:
    if last != -1:
      ans += 1
      last = -1

print(ans)
