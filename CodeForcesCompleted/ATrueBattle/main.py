for _ in range(int(input())):
    n = int(input())
    a = list(map(int, list(input())))
    if a[0] == 1 or a[-1] == 1:
        print("YES")
        continue
    for i in range(n - 1):
        if a[i] == a[i + 1] == 1:
            print("YES")
            break
    else:
        print("NO")