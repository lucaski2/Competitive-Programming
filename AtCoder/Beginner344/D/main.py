from typing import Dict, List, Tuple
def min_path(grid: List[List[int]], grid_idx: int, target_str: str, target_str_idx: int, memo: Dict[Tuple[int, int], float]) -> float:
    if grid_idx == len(grid):
        if target_str_idx < len(target_str):
            return float("inf")
        else:
            return 0

    memoized = memo.get((grid_idx, target_str_idx))
    if memoized is not None:
        return memoized

    min_path_val = float("inf")
    for col in range(len(grid[grid_idx])):
        prefix = grid[grid_idx][col]
        
        if not target_str.startswith(prefix, target_str_idx):
            continue
        path_val = 1 + min_path(grid, grid_idx + 1, target_str, target_str_idx + len(prefix), memo)
        min_path_val = min(min_path_val, path_val)
    min_path_val = min(min_path_val, min_path(grid, grid_idx + 1, target_str, target_str_idx, memo))

    memo[(grid_idx, target_str_idx)] = min_path_val
    return min_path_val


    



t = input()
n = int(input())


dp = [[float("inf") for _ in range(105)] for _ in range(105)]
dp[0][0] = 0

for i in range(n):
    lst = input().split(" ")
    u = int(lst[0])
    lst = lst[1:]


    for k in range(u):
        for j in range(105):

            if t.startswith(lst[k], j):
                dp[i][j + len(lst[k])] = min(dp[i][j + len(lst[k])], dp[i][j] + 1)
    for j in range(105):
        dp[i + 1][j] = dp[i][j]

m = float('inf')

for i in range(n):
    m = min(m, dp[i][len(t)])

if m == float('inf'):
    print(-1)

else:
    print(m)






