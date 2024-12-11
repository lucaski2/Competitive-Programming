
def gcd(a, b):
  while b:
    a, b = b, a % b
  return a


for _ in range(int(input())):
  n = int(input())
  a = list(map(int, input().split()))
  
  gc = a[0]
  for i in range(1, n):
    gc = gcd(gc, a[i])

  print(a[n - 1] // gc)
