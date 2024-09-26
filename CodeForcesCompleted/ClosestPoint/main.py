
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a = list(set(a))
    if len(a) > 2:
        print("NO")
        continue
    a.sort()
    if a[0] == a[1] - 1:
        print("NO")
    else:
        print("YES")
        