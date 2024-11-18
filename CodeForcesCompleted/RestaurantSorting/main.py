
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n):
        if a[i] != i + 1:
            print(n - i)
            break
    else:
        print(0)