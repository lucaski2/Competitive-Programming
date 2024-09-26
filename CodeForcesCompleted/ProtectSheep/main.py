
def items_around(grid, i, j):
    items = []
    if i > 0:
        items.append(grid[i-1][j])
    if i < len(grid) - 1:
        items.append(grid[i+1][j])
    if j > 0:
        items.append(grid[i][j-1])
    if j < len(grid[0]) - 1:
        items.append(grid[i][j+1])
    return items

n, m = map(int, input().split())
grid = [list(input()) for _ in range(n)]
works = True
for i in range(n):
    for j in range(m):
        if grid[i][j] == 'W':
            for item in items_around(grid, i, j):
                if item == 'S':
                    works = False
        if grid[i][j] == '.':
            grid[i][j] = 'D'
if works:
    print('YES')
    for row in grid:
        print(''.join(row))
else:
    print("NO")
