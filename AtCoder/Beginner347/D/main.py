

from typing import Dict, List, Tuple


def min_path(grid: List[List[int]], grid_idx: int, target_str: str, target_str_idx: int, memo: Dict[Tuple[int, int], float]) -> float:
    if grid_idx == len(grid):
        if target_str_idx > 0:
            return float("inf")
        else:
            return 0

    memoized = memo.get((grid_idx, target_str_idx))
    if memoized is not None:
        return memoized

    min_path_val = float("inf")
    for col in range(len(grid[0])):
        prefix = grid[grid_idx][col]
        if not target_str.startswith(prefix, target_str_idx):
            continue
        path_val = 1 + min_path(grid, grid_idx + 1, target_str, target_str_idx + len(prefix))
        min_path_val = min(min_path_val, path_val)
    min_path_val = min(min_path_val, min_path(grid, grid_idx + 1, target_str, target_str_idx))

    memo[(grid_idx, target_str_idx)] = min_path_val
    return min_path_val

