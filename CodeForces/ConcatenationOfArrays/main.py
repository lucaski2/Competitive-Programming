
for _ in range(int(input())):
    n = int(input())
    arrs = [list(map(int, input().split())) for _ in range(n)]
    arrs.sort(key=lambda x: sum(x))
    for arr in arrs:
        print(*arr, end=' ')
    print()