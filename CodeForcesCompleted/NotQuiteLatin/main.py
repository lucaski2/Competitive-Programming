
for _ in range(int(input())):
    grid = [list(input()) for _ in range(3)]
    
    for i in range(3):
        for j in range(3):
            if grid[i][j] == '?':
                lst = list('ABC')
                lst.remove(grid[i][j - 1])
                lst.remove(grid[i][j - 2])
                print(lst[0])


