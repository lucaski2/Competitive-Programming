
n, t, p = map(int, input().split())
a = list(map(int, input().split()))
ans = 0

while True:
    am = 0
    for i in range(n):
        if a[i] >= t:
            am += 1
    if am >= p:
        print(ans)
        exit()
    
    for i in range(n):
        if a[i] < t:
            a[i] += 1

    ans += 1



