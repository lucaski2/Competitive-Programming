
for _ in range(int(input())):
  m, n, k = map(int, input().split())

  best = []
  amount_marbles = [m] * n
  for i in range(n):
    inp = list(map(int, input().split()))
    odd = max([x for x in inp if x % 2 == 1] + [0])
    even = max([x for x in inp if x % 2 == 0] + [0])

    if odd == 0:
      odd = -min([x for x in inp if x % 2 == 0])
    if even == 0:
      even = -min([x for x in inp if x % 2 == 1])
    
    if even > odd:
      best.append([0, odd, even])
    else:
      best.append([1, even, odd])
    if i != 0:
      amount_marbles[i] = max(0, amount_marbles[i - 1] - best[-1][1])
    if i == 0:
      amount_marbles[i] = max(0, amount_marbles[i] - best[-1][1])
  if 0 in amount_marbles:
    print(-1)
    continue
  
  min_marbles = [1000000] * n
  for i in range(n - 1, -1, -1):
    if i == n - 1:
      min_marbles[i] = amount_marbles[i]
    else:
      min_marbles[i] = min(min_marbles[i + 1], amount_marbles[i])
  
  offset = 0
  for i in range(n):
    if best[i][0] == 1:
      am = min_marbles[i] - offset
      if am > 1 and am > abs(best[i][2] - best[i][1]):
        offset += best[i][2] - best[i][1]
        best[i][0] = 0
    
  for i in range(n):
    if best[i][0] == 1:
      print("Odd", end='')
    else:
      print("Even", end='')
    if i != n - 1:
      print(" ", end='')
  print()
  

  
  




