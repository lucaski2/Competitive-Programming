
def eval(mid, n, k, a):
  cnt = 0
  for i in range(n // 2, n):
    if a[i] < mid:
      cnt += mid - a[i]
    if cnt > k:
      return False
  return cnt <= k


n, k = map(int, input().split())
a = list(map(int, input().split()))

a.sort()
l = 0
r = 2*10**9
ans = 0
while l < r:
  mid = (l + r + 1) // 2
  

  if eval(mid, n, k, a):
    ans = mid
    l = mid
  else:
    r = mid - 1
print(ans)