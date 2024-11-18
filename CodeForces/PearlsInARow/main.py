
n = int(input())
a = list(map(int, input().split()))

ans = []
cur = set()
for i in range(n):
    if a[i] in cur:
        ans.append((i - len(cur) + 1, i + 1))
        cur = set()
    else:
        cur.add(a[i])

if len(ans) == 0:
    print(-1)
else:
    print(len(ans))
    if len(cur) > 0:
        ans[-1] = (ans[-1][0], n)
    for l, r in ans:
        print(l, r)
