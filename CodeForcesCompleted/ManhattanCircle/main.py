from math import ceil
for _ in range(int(input())):
    n, m = list(map(int, input().split()))

    grid = [list(input()) for _ in range(n)]

    # for i in range(n):
    #     print(*grid[i])

    printed = False

    if [grid[i][j] for i in range(n) for j in range(m)].count("#") == 1:
        for i in range(n):
            for j in range(m):
                if grid[i][j] == "#":
                    print(i + 1, j + 1)
                    printed = True
                    break
            if printed:
                break

    else:
        for i in range(n):
            if grid[i].count("#") > grid[i + 1].count("#"):
                count = grid[i].count("#")
                cur = 0
                for j in range(m):
                    if grid[i][j] == "#":
                        cur += 1
                    
                    if cur == count // 2 + 1:
                        print(i + 1, j + 1)
                        printed = True
                        break
            if printed:
                break


