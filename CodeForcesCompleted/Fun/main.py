
for _ in range(int(input())):
    n, x = map(int, input().split())
    ans = 0
    for a in range(1, n + 1):
        b = 1
        while b * a <= n:
            c = min(x - a - b, int((n - (a * b)) / (a + b)))
            if c > 0:
                ans += c
            b += 1
    print(ans)