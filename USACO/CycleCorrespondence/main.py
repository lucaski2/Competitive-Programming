
n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

ind = {}

for i in range(k):
    a[i] -= 1
    b[i] -= 1
    ind[b[i]] = i

dists = [0] * k
for i in range(k):
    if a[i] not in ind:
        continue
    n1 = i
    n2 = ind[a[i]]
    if n1 >= n2:
        dist = n1 - n2
    else:
        dist = k - n2 + n1
    dists[dist] += 1

m = max(dists)

ind = {}
b.reverse()
for i in range(k):

    ind[b[i]] = i

dists = [0] * k
for i in range(k):
    if a[i] not in ind:
        continue
    n1 = i
    n2 = ind[a[i]]
    if n1 >= n2:
        dist = n1 - n2
    else:
        dist = k - n2 + n1
    dists[dist] += 1

m = max(m, max(dists))

found = [False] * n
for i in range(k):
    found[a[i]] = True
    found[b[i]] = True

print(m + found.count(False))




