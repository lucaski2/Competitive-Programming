
for _ in range(int(input())):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    ans = 0
    a.reverse()
    b.reverse()
    for i in range(n - m):
        ans += min(a[i], b[i])
    
    a.reverse()
    b.reverse()
    a = a[:m]
    b = b[:m]
    cur_s = 0
    a.reverse()
    b.reverse()
    mi = 10000000000000000
    for i in range(m):
        
        mi = min(mi, a[i] + cur_s)

        cur_s += b[i]
    print(mi + ans)
