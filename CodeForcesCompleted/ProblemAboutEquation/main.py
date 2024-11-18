
n, b = map(int, input().split())
a = list(map(int, input().split()))

m = max(a)
ans = [0] * n

for i in range(n):
    am = m - a[i]
    if am < 0:
        print(-1)
        exit()
    a[i] += am
    ans[i] += am
    b -= am
if b < 0:
    print(-1)
    exit()
am = b / n
for i in range(n):
    ans[i] += am
print(*ans, sep='\n')



