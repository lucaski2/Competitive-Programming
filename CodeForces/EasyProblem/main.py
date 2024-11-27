
n, m = map(int, input().split())
a = list(map(int, input().split()))

print(min(min(a), m - sum(a)))

