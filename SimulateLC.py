
def is_beautiful(n):
  s = str(n)
  p = 1
  s2 = 0;
  for c in s:
    p *= int(c)
    s2 += int(c)
  
  return p % s2 == 0



ans = 0;
for i in range(1, int(1e9)):
  ans += is_beautiful(i)
print(ans)