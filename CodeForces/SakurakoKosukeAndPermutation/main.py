
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    inds = {}
    for i in range(n):
        a[i] -= 1
        inds[a[i]] = i

    ans = 0
    for i in range(n // 2):
        cur1 = inds[i]
        cur2 = inds[n - i - 1]
        if cur1 == i or cur1 == n - i - 1:
            if cur2 == i or cur2 == n - i - 1:
                ans += 0
            else:
                


