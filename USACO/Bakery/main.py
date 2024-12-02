from math import ceil, floor

for _ in range(int(input())):
  input()
  n, muffin, bread = map(int, input().split())
  
  needs = [list(map(int, input().split())) for _ in range(n)]

  ans = 10000000000

  for i in range(muffin):
    m = 0
    ok = True
    for j in range(n):
      num_muffin, num_bread, time = needs[j]
      
      time_left = time - ((muffin - i) * num_muffin)
      if time_left < 0:
        ok = False
        break
      if time_left >= bread * num_bread:
        m = max(m, i)
        continue
      part2 = ceil((num_bread * bread - time_left) / num_bread)
      if part2 >= bread:
        ok = False
        break
      m = max(m, i + part2)
      
    if ok:
      ans = min(ans, m)


  print(ans)
