
for _ in range(int(input())):
    n, x, y = map(int, input().split())
    a = list(map(int, input().split()))

    ax = [a[i] % x for i in range(n)]
    ay = [a[i] % y for i in range(n)]
    d = {}
    
    for i in range(n):
        if (ax[i], ay[i]) not in d:
            d[(ax[i], ay[i])] = 0
        d[(ax[i], ay[i])] += 1
    ans = 0
    for i in range(n):
        if ax[i] == 0:
            ans += d[(ax[i], ay[i])] - 1
        elif (x - ax[i], ay[i]) in d:
            ans += d[(x - ax[i], ay[i])]
            if (ax[i], ay[i]) == (x - ax[i], ay[i]):
                ans -= 1
        d[(ax[i], ay[i])] -= 1
    print(ans)