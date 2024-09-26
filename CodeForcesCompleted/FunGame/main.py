
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, list(input())))
    b = list(map(int, list(input())))
    m1 = 10000000
    m2 = 10000000

    for i in range(n):
        if b[i] == 1:
            m2 = min(i, m2)
        if a[i] == 1:
            m1 = min(i, m1)
    if m1 <= m2:
        print("YES")
    else:
        print("NO")
