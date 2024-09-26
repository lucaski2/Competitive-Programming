
def check_bingo(grid, last_placement):
    # very low time complexity because you just need to check for connections from last placement
    for i in range(len(grid)):
        if grid[i][last_placement[1]] == 0:
            break
    else:
        return True

    for i in range(len(grid[0])):
        if grid[last_placement[0]][i] == 0:
            break
    else:
        return True

    for i in range(len(grid)):
        if grid[i][i] == 0:
            break
    else:
        return True

    for i in range(len(grid)):
        if grid[i][len(grid) - i - 1] == 0:
            break
    
    else:
        return True






n, t = map(int, input().split())
a = list(map(int, input().split()))
grid2 = [[0 for _ in range(n)] for _ in range(n)]




for i in range(t):
    # get coordinates from number
    x = (a[i] - 1) // n
    y = (a[i] - 1) % n
    grid2[x][y] = 1

    if check_bingo(grid2, (x, y)):
        print(i + 1)
        exit()

print(-1)


