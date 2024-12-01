
n = int(input())
a = list(map(int, input().split()))


for i in range(1, a[0]):
  #simulate
  cur = [0] * n
  cur[0] = i
  for j in range(1, n):
    cur[j] = a[j-1] - cur[j-1]
  
  if list(sorted(cur)) == list(range(1, n+1)):
    print(' '.join(map(str, cur)))

