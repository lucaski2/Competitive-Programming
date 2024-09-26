

def is_valid(grid, i: tuple, j:tuple, k:tuple):
    # if i is adjacent to j and j is adjacent to k diagonally included
    if abs(i[0] - j[0]) <= 1 and abs(i[1] - j[1]) <= 1 and abs(j[0] - k[0]) <= 1 and abs(j[1] - k[1]) <= 1:
        return True
    return False



grid = [list(input()) for _ in range(3)]

lowest = "CCC"



for i in range(3):
    for j in range(3):
        for k in range(3):
            for l in range(3):
                for m in range(3):
                    for n in range(3):
                        # if grid[i][j] + grid[k][l] + grid[m][n] == "ABC":
                        #     print(i, j, k, l, m, n)
                        if grid[i][j] + grid[k][l] + grid[m][n] < lowest and is_valid(grid, (i, j), (k, l), (m, n)) and (i, j) != (k, l) and (i, j) != (m, n) and (k, l) != (m, n):
                            lowest = grid[i][j] + grid[k][l] + grid[m][n]


print(lowest)