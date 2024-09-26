
for _ in range(int(input())):
    n, c = map(int, input().split())
    a = list(map(int, input().split()))

    for i in range(n):
        a[i] += i + 1
    
    a.sort()
    ind = 0
    while c > 0 and ind < n:
        if a[ind] <= c:
            c -= a[ind]
            ind += 1
        else:
            break
    print(ind)


