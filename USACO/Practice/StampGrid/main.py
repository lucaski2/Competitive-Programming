
def rotate(m):
    # rotate grid 90 degrees to the right

    # get the size of the grid
    size = len(m)
    # create a new grid to store the rotated values
    rotated = [[0 for _ in range(size)] for _ in range(size)]
    # iterate over the rows of the original grid
    for i in range(size):
        # iterate over the columns of the original grid
        for j in range(size):
            # assign the value from the original grid to the new grid
            # with the columns and rows swapped
            rotated[j][size-i-1] = m[i][j]

    return rotated

def stamp_sheet(g1, g2, x, y):
    ret = []
    for i in range(len(g1)):
        ret.append(g1[i].copy())
    for i in range(len(g2)):
        for j in range(len(g2[0])):
            if g2[i][j] == "*":
                ret[x+i][y+j] = g2[i][j]
    return ret

def allowed(g1, g2):
    for i in range(len(g2)):
        for j in range(len(g2[0])):
            if g1[i][j] == "." and g2[i][j] == "*":
                return False
    return True

def get_positions(n, k):
    # get possible coordinates of top left corner so that the stamp can be placed in the canvas
    positions = []
    for i in range(n-k+1):
        for j in range(n-k+1):
            positions.append((i, j))

    return positions

def difference(start_grid, end_grid):
    dif = 0
    for i in range(len(start_grid)):
        for j in range(len(start_grid[0])):
            if start_grid[i][j] != end_grid[i][j]:
                dif += 1
    return dif

inp = int(input())

for _ in range(inp):
    input()
    n = int(input())
    target_grid = [list(input()) for _ in range(n)]
    grid = [["." for _ in range(n)] for _ in range(n)]
    k = int(input())
    stamp = [list(input()) for _ in range(k)]


    possible_positions = get_positions(n, k)

    nothing_count = 0

    while grid != target_grid:
        possibilities = {}
        for pos in possible_positions:
            cur = stamp_sheet(grid, stamp, pos[0], pos[1])
            if allowed(target_grid, cur):
                possibilities[pos] = difference(grid, cur)
        # print(possibilities)
        # print_grid(grid)
        if len(possibilities) == 0:
            nothing_count += 1
            stamp = rotate(stamp)
            if nothing_count >= 4:
                print("NO")
                break
            continue
        elif max(possibilities.values()) == 0:
            nothing_count += 1
            stamp = rotate(stamp)

            if nothing_count >= 4:
                print("NO")
                break
            continue
        else:
            nothing_count = 0
        max_pos = max(possibilities, key=possibilities.get)
        grid = stamp_sheet(grid, stamp, max_pos[0], max_pos[1])
    else:
        print("YES")






