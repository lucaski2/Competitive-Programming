from copy import deepcopy

def rotate_grid_90(grid):
    # rotate the grid 90 degrees clockwise
    return [list(row) for row in zip(*grid[::-1])]

def print_page(grid):
    for g in grid:
        print("".join(g))

def stamp_page(grid, stamp, end_grid, x, y):
    k = len(stamp)

    for i in range(k):
        for j in range(k):
            if stamp[i][j] == '*' and end_grid[x + i][y + j] == '.':
                return

    for i in range(k):
        for j in range(k):
            grid[x+i][y+j] = '*' if stamp[i][j] == '*' else grid[x+i][y+j]


for _ in range(int(input())):

    n = input()
    while n == '':
        n = input()
    n = int(n)
    page = [list(input()) for _ in range(n)]
    k = int(input())
    stamp = [list(input()) for _ in range(k)]
    cur_page = [['.' for _ in range(n)] for _ in range(n)]
    rotates = [stamp]
    for _ in range(3):
        rotates.append(rotate_grid_90(rotates[-1]))
    
    for i in range(n - k + 1):
        for j in range(n - k + 1):
            for cur in rotates:
                s = stamp_page(cur_page, cur, page, i, j)
    # print_page(cur_page)
    if cur_page == page:
        print("YES")
    else:
        print("NO")






