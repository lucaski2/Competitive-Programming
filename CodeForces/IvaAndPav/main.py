
for _ in range(int(input())):
  n = int(input())
  a = list(map(int, input().split()))
  # prefix sum with each bit
  pref_sum = [[0] * 32 for i in range(n)]
  for i in range(n):
    for j in range(32):
      pref_sum[i][j] = (a[i] >> j) & 1
      if i > 0:
        pref_sum[i][j] += pref_sum[i - 1][j]
  

  q = int(input())
  for _ in range(q):
    l, k = map(int, input().split())
    l -= 1
    if k > a[l]:
      print(-1, end=' ')
      continue

    # binary search for the largest r such that a[l] & a[l + 1] & ... & a[r] >= k
    cur_l = l
    cur_r = n
    

  

    while cur_l < cur_r:
      mid = (cur_l + cur_r) // 2
      ok = False
      num = 0
      for j in range(32):
        # num is incremented by 1 >> j if all bits from l to mid are 1
        if pref_sum[mid][j] - (pref_sum[l - 1][j] if l > 0 else 0) == mid - l + 1:
          num += 1 << j
      if num >= k:
        ok = True

      if ok:
        cur_l = mid + 1
      else:
        cur_r = mid

    print(cur_l, end=' ')
  print()

