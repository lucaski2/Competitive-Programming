
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a[a.index(min(a))] += 1
    ans = 1
    for i in range(n):
        ans *= a[i]
    print(ans)