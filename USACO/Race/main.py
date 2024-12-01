

k, n = map(int, input().split())

for _ in range(n):
  x = int(input())

  dist = 0
  time = 0
  for speed in range(1, 100000):
    dist += speed
    time += 1
    if dist >= k:
      print(time)
      break

    if speed >= x:
      dist += speed
      time += 1
    if dist >= k:
      print(time)
      break

