
for _ in range(int(input())):
    n, k = map(int, input().split())
    if n != k and k != 1:
        print(-1)
    else:
        if n == k:
            print('1 ' * n)
        else:
            print('1 ' * (n - 1) + '2')
