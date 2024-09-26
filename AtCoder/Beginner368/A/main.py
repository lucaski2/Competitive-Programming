n, k = map(int, input().split())
a = list(map(int, input().split()))
a = a[n-k:] + a[:n-k]
print(*a)