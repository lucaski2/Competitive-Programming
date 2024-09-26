
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort(reverse=True)
    s1 = 0
    for i in range(0, n, 2):
        s1 += a[i]
    s2 = 0
    for i in range(1, n, 2):
        cur = min(k, a[i - 1] - a[i])
        s2 += cur + a[i]
        k -= cur
    print(s1 - s2)