
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(2, n):
        if a[i] % 2 != a[i - 2] % 2:
            print("NO")
            break   
    else:
        print("YES")