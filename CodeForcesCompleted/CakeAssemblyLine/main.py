
for _ in range(int(input())):
    n, w, h = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    r = [-float('inf'), float('inf')]
    
    for i in range(n):
        r[0] = max(r[0], b[i] - a[i] - w)
        r[1] = min(r[1], b[i] - a[i] + w - 2 * h)
    print("YES" if r[0] <= r[1] else "NO")




