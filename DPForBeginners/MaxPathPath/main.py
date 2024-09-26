
def maxPath(grid):
    m, n = len(grid), len(grid[0])
    dp = [[0 for _ in range(n)] for _ in range(m)]

    for i in range(n):
        for j in range(m):
            dp[i][j] = grid[i][j]
            if i > 0 and j > 0:
                dp[i][j] += max(dp[i-1][j], dp[i][j-1])
            
            elif i > 0:
                dp[i][j] += dp[i-1][j]
            elif j > 0:
                dp[i][j] += dp[i][j-1]
            
    
    path = []

    cur_point = (m-1, n-1)

    while cur_point != (0, 0):
        path.append(cur_point)
        i, j = cur_point
        if i == 0:
            cur_point = (i, j-1)
        elif j == 0:
            cur_point = (i-1, j)
        else:
            if dp[i-1][j] > dp[i][j-1]:
                cur_point = (i-1, j)
            else:
                cur_point = (i, j-1)
        
    
    path.append((0, 0))
    path.reverse()
    return path

