
for _ in range(int(input())):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    s = 0
    for i in range(n):
        s += a[i]
    print(max(0, s - m))
