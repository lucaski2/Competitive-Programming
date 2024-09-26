
for _ in range(int(input())):
    n, x = map(int, input().split())
    a = [0] + list(map(int, input().split()))
    a.append(x + (x - a[-1]))
    # print(a)
    m = 0
    for i in range(n + 1):
        m = max(m, abs(a[i] - a[i + 1]))
    print(m)