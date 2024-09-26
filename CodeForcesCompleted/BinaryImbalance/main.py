
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, list(input())))
    if a.count(1) == n:
        print("NO")
    else:
        print("YES")