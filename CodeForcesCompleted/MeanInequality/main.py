
for _ in range(int(input())):
    n = int(input())
    
    a = list(map(int, input().split()))
    a.sort()
    for i in range(n):
        print(a[i], a[2 * n - i - 1], end=' ')
    print()
