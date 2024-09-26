
for _ in range(int(input())):
    n, m = map(int, input().split())
    grid = [list(input()) for _ in range(n)]
    black = True
    white = True
    slices = [grid[0], grid[-1], [grid[i][0] for i in range(n)], [grid[i][-1] for i in range(n)]]
    for sl in slices:
        if "B" not in sl:
            black = False
        if "W" not in sl:
            white = False
    if black or white:
        print("YES")
    else:
        print("NO")

