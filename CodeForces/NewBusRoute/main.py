
n = int(input())
a = list(map(int, input().split()))

a.sort()
m = 10000000000
q = 0

for i in range(1, n):
    if a[i] - a[i - 1] < m:
        m = a[i] - a[i - 1]
        q = 1
    elif a[i] - a[i - 1] == m:
        q += 1

print(m, q)

