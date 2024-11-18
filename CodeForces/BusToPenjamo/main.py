
for _ in range(int(input())):
    n, r = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        am = min(a[i] // 2, r)
        ans += am * 2
        r -= am
        a[i] -= am * 2
    
    am_left = sum(a)
    ans += min(am_left, (r * 2 - am_left))
    print(ans)
