


for _ in range(int(input())):
    n = int(input())
    p = list(map(int, input().split()))

    ans = []
    for i in range(n):
        if p[i] == 1:
            print(n, end=' ')
        else:
            print(p[i] - 1, end=' ')
    print()