
for _ in range(int(input())):
    n, k = map(int, input().split())
    grid = [list(input()) for _ in range(n)]
    red = n // k
    reduced_grid = [[0 for _ in range(red)] for _ in range(red)]

    for i in range(red):
        for j in range(red):
            reduced_grid[i][j] = grid[i * k][j * k]
    
    for line in reduced_grid:
        print(''.join(line))



