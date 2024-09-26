for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    smallest = min(a)
    ind = a.index(smallest)
    if a[ind:] != list(sorted(a[ind:])):
        print(-1)
    else:
        print(ind)

