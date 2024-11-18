
n, k = map(int, input().split())
a = list(map(int, input().split()))

cur = 0
ind = 0
for i in range(n):
    if cur + i + 1 >= k:
        ind = i
        break
    cur += i + 1

k -= cur
print(a[k - 1])


