
t = input()
for testcase in range(int(t)):
  n = int(input())
  a = [int(x) for x in input().split()]
  am_reach = int(n / 2 - 0.5)
  s = sum(a)
  ans = 0
  ind1 = 0
  ind2 = n - am_reach
  cur_s = 0
  for i in range(n - 1, n - am_reach - 1, -1):
    cur_s += a[i]

  for i in range(am_reach):
    ans = max(ans, cur_s)
    cur_s -= a[ind2]
    cur_s += a[ind1]
    # print(a[ind1], a[ind2])
    ind1 += 1
    ind2 += 1
  ans = max(ans, cur_s)
  
  print(s - ans, ans)
  