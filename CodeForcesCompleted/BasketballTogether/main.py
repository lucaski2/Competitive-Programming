from math import ceil
n, d = map(int, input().split())
a = list(map(int, input().split()))
a.sort(reverse=True)
ind = 0

while n > 0:
    cur = a[ind]
    am = ceil(d / cur + 0.0000000001)
    if am > n:
        break
    n -= am
    ind += 1
    # print(n)
print(ind)





