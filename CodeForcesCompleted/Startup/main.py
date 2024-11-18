
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = [list(map(int, input().split())) for i in range(k)]

    mon = [0] * (k + 2)
    for i in range(k):
        mon[a[i][0] - 1] += a[i][1]

    mon.sort(reverse=True)

    ans = 0
    for i in range(min(n, len(mon))):
        ans += mon[i]
    print(ans)
