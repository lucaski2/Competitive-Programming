
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    s1 = 0
    s2 = 0
    for i in range(n):
        if a[i] > b[i]:
            s2 += a[i]
        elif a[i] < b[i]:
            s1 += b[i]
        elif a[i] == b[i] == 0:
            continue

    for i in range(n):
        if a[i] != b[i]:
            continue
        elif a[i] == b[i] == 0:
            continue
        cur = a[i]
        if s1 >= s2:
            if cur > 0:
                s2 += cur
            else:
                s1 += cur
        else:
            if cur > 0:
                s1 += cur
            else:
                s2 += cur
    print(min(s1, s2))
    
