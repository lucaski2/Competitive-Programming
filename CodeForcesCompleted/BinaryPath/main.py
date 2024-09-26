
for _ in range(int(input())):
    n = int(input())
    grid = [list(input()) for _ in range(2)]
    smallest = ""
    cur = [0, 0]
    while cur != [1, n - 1]:
        smallest += str(grid[cur[0]][cur[1]])
        possibilities = []
        if cur[1] < n - 1:
            possibilities.append([cur[0], cur[1] + 1])
        if cur[0] < 1:
            possibilities.append([cur[0] + 1, cur[1]])
        if len(possibilities) == 1:
            cur = possibilities[0]
        elif grid[possibilities[0][0]][possibilities[0][1]] <= grid[possibilities[1][0]][possibilities[1][1]]:
            cur = possibilities[0]
        else:
            cur = possibilities[1]
    smallest += str(grid[cur[0]][cur[1]])

    dp = [[0 for _ in range(n)] for _ in range(2)]
    dp[0][0] = 1

    for i in range(2):
        for j in range(n):
            if i == 0 and j == 0:
                continue
            if grid[i][j] == smallest[i + j]:
                if i > 0:
                    dp[i][j] += dp[i - 1][j]
                if j > 0:
                    dp[i][j] += dp[i][j - 1]


    print(smallest)
    print(dp[1][n - 1])


