
a = list(map(int, input().split()))
a.sort()
print(a[0], a[1], end=' ')
a.remove(a[0] + a[1])
a = a[2:]
print(a[0])


