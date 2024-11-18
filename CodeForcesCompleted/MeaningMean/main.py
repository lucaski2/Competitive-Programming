
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    cur = a[0]
    for i in range(1, n):
        cur = int((cur + a[i]) / 2)
    print(cur)