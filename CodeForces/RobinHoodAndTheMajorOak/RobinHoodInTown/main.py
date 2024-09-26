
for _ in range(int(input())):
    n = int(input())


    a = list(map(int, input().split()))
    if n == 1 or n == 2:
        print(-1)
        continue
    a.sort()
    m = a[n // 2] * 2
    s = sum(a)
    s_must_be = m * n
    am = s_must_be - s
    print(max(0, am + 1))
