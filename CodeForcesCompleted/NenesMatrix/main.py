
for _ in range(int(input())):
    n = int(input())
    s = 0
    for i in range(1, n + 1):
        s += (i * 2 - 1) * i
    print(s, 2 * n)
    perm = [i for i in range(1, n + 1)]

    for i in range(n, 0, -1):
        print(1, i, *perm)
        print(2, i, *perm)
    