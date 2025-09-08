
n = int(input())


for i in range(1, int(2500000)):
  if (i * i * i <= n): continue
  diff = i * i * i - n
  
  # bin search :sob: why 
  l = 1
  r = i
  ok = False
  while (l <= r):
    mid = (l + r) // 2
    num = mid ** 3
    if (num == diff):
      ok = True
      print(i, mid)
      break
    elif num < diff:
      l = mid + 1
    else:
      r = mid - 1
  if ok: break


else:
  print(-1)



