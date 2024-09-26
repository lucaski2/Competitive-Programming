
for _ in range(int(input())):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    m = max(a)

    for i in range(q):
        t, a, b = input().split()
        a = int(a)
        b = int(b)
        if t == '+' and b >= m and a <= m:
            m += 1
        elif t == '-' and b >= m and a <= m:
            m -= 1
        print(m, end=' ')
    print()