
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    s = {}
    for i in range(n):
        if a[i] in s:
            s[a[i]] += 1
        else:
            s[a[i]] = 1
    ans = 0
    for i in s.values():
        if i >= 2:
            ans += 1
    print(ans)