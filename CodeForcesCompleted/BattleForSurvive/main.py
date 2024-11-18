
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = a[-1] - (a[-2] - sum(a[:-2] if len(a) > 2 else [0]))
    print(ans)