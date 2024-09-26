
for _ in range(int(input())):
    a = list(map(int, input().split()))
    a.sort()
    print(a[0] if a.count(a[0]) == 1 else a[-1])

