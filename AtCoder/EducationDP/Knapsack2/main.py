
def solve(grid, ind, value, weight, memo, w):
    if ind == len(grid):
        return value
    if (ind, weight) in memo and memo[(ind, weight)] >= value:
        return memo[(ind, weight)]
    
    memo[(ind, weight)] = value
    m = 0
    if weight + grid[ind][0] <= w:
        m = solve(grid, ind + 1, value + grid[ind][1], weight + grid[ind][0], memo, w)
    return max(m, solve(grid, ind + 1, value, weight, memo, w))


    

n, w = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

print(solve(grid, 0, 0, 0, {}, w))






