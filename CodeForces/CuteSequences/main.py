
for _ in range(int(input())):

  a, b, m = map(int, input().split())

  ok = False

  for length in range(1, 51):
    cur_sum = a
    cur_num = a
    
    for i in range(1, length):
      cur_num = cur_sum + 1
      cur_sum += cur_num
    
    if (cur_num > b):
      continue

    cur_sum = a
    cur_num = a

    for  i in range(1, length):
      cur_num = cur_sum + m
      cur_sum += cur_num
    
    if cur_num < b:
      continue
      
    running_sum = a
    last_num = a

    ans = [a]

    for i in range(1, length):
      l = 1
      r = m
      found = -1
      while l <= r:
        mid = (l + r) // 2
        cur_sum = running_sum
        cur_num = last_num
        cur_num = cur_sum + mid
        cur_sum += cur_num

        for j in range(i + 1, length):
          cur_num = cur_sum + 1
          cur_sum += cur_num
        
        if cur_num > b:
          r = mid - 1
        else:
          l = mid + 1
          found = mid
      
      if found != -1:
        last_num = running_sum + found
        ans.append(last_num)
        running_sum += last_num
    
    if last_num == b:
      print(length, end=' ')
      print(*ans)
      ok = True
      break
  if not ok:
    print(-1)


