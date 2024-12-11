
n = int(input())
a = list(map(int, input().split()))

a.sort()
cur = sum(a)
ind = 0 
while cur / n < 4.5:
  cur += 5 - a[ind]
  a[ind] = 5
  ind += 1
  
print(ind)

