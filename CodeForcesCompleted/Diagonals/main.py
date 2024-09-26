
for _ in range(int(input())):
    n, k = map(int, input().split())
    counts = [i for i in range(1, n + 1)]
    counts += [i for i in range(1, n)]
    counts.sort()
    ans = 0
    while k > 0:
        k -= counts.pop()
        ans += 1
    print(ans)


