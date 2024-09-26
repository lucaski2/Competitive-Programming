
def rotate_grid_90(grid):
    n = len(grid)
    rotated_grid = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            rotated_grid[j][n - i - 1] = grid[i][j]
    return rotated_grid


for _ in range(int(input())):
    n = int(input())
    grid1 = [list(map(int, list(input()))) for _ in range(n)]
    grid2 = rotate_grid_90(grid1)
    grid3 = rotate_grid_90(grid2)
    grid4 = rotate_grid_90(grid3)
    ans = 0
    for i in range(n):
        for j in range(n):
            count_zero = 0
            count_ones = 0
            for num in [grid1[i][j], grid2[i][j], grid3[i][j], grid4[i][j]]:
                if num == 0:
                    count_zero += 1
                else:
                    count_ones += 1
            ans += 4 - max(count_zero, count_ones)
    print(ans // 4)
