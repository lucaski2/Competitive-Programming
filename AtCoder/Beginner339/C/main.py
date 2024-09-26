
n = int(input())
a = list(map(int, input().split()))
m = 0
cur = 0
for i in range(n):
    cur += a[i]
    m = min(m, cur)

print(cur - m)