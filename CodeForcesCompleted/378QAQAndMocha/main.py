
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    m = a[0]
    end = []
    for i in range(n):
        if a[i] % m != 0:
            end.append(a[i])
    if len(end) == 0:
        print("YES")
        continue
    m = end[0]
    for i in range(len(end)):
        if end[i] % m != 0:
            print("NO")
            break
    else:
        print("YES")


