
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    m = min(a)
    if a[0] > m or a[-1] > m:
        print("NO")
    else:
        print("YES")

