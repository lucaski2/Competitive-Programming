
n, m = map(int, input().split())

s = list(input())
a = list(map(int, input().split()))
ans = sum(a)
for i in range(n):
  if s[i] == 'L' and s[(i - 1) % n] == 'R' and s[(i + 1) % n] == 'L':
    # well
    ind = (i - 1) % n
    am = 0
    while s[ind] == 'R':
      am += a[ind]
      ind = (ind - 1) % n
    ans -= min(am, m)
  if s[i] == 'R' and s[(i + 1) % n] == 'L' and s[(i - 1) % n] == 'R':
    # well
    ind = (i + 1) % n
    am = 0
    while s[ind] == 'L':
      am += a[ind]
      ind = (ind + 1) % n
    ans -= min(am, m)
print(ans)
