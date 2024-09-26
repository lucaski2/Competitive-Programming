height, width = list(map(int, input().split()))

grid = [list(input()) for _ in range(height)]

def check_around(lst, i, j):
    lst = []
    if i > 0:
        lst.append(grid[i-1][j])
    
    if j > 0:
        lst.append(grid[i][j-1])
    
    if i < height - 1:
        lst.append(grid[i+1][j])
    
    if j < width - 1:
        lst.append(grid[i][j+1])
    
    return lst
# num_assigned = sum([line.count(".") for line in grid])

rng_list = list(map(str, list(range(1, 100))))

for current_num in range(1, 100):
    for i in range(height):
        for j in range(width):
            # assign all 1s
            if grid[i][j] == "T" or grid[i][j] in rng_list:
                current_check = check_around(grid, i, j)
                if current_check.count(".") != 0 or len(current_check) != 4:
                    grid[i][j] = "1"

                if current_num != 1:
                    if current_check.count(str(current_num - 1)) + current_check.count("T") + current_check.count(str(current_num)) == 4:
                        grid[i][j] = str(current_num)

                
num_chars = max([len(c) for l in grid for c in l]) + 1
for line in grid:
    for char in line:
        print('.' * (num_chars - len(char)), end="")
        print(char, end="")
    
    print()