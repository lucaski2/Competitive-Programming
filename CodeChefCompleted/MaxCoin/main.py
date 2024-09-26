
for _ in range(int(input())):
    n, x = map(int, input().split())
    ans = 0
    for i in range(1, n + 1):
        if n - x < i:
            ans += pow(2, i)
        else:
            ans -= pow(2, i)


    print(ans)