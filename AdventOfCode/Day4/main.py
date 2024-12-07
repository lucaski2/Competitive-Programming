def count_xmas(grid):
    rows = len(grid)
    cols = len(grid[0])
    count = 0

    # Check if a "MAS" exists along a diagonal direction
    def is_mas(r, c, dr, dc):
        try:
            return (
                grid[r][c] == 'M' and
                grid[r + dr][c + dc] == 'A' and
                grid[r + 2 * dr][c + 2 * dc] == 'S'
            )
        except IndexError:
            return False  # Out of bounds

    # Loop through every cell in the grid
    for r in range(rows):
        for c in range(cols):
            # Check all combinations of two "MAS" patterns crossing at (r, c)
            if (
                # Forward diagonal (top-left to bottom-right) + Reverse diagonal (top-right to bottom-left)
                is_mas(r - 1, c - 1, 1, 1) and is_mas(r - 1, c + 1, 1, -1)
            ) or (
                # Forward diagonal (top-left to bottom-right) + Reverse forward diagonal (bottom-left to top-right)
                is_mas(r - 1, c - 1, 1, 1) and is_mas(r + 1, c - 1, -1, 1)
            ) or (
                # Backward diagonal (bottom-right to top-left) + Forward diagonal (bottom-left to top-right)
                is_mas(r + 1, c + 1, -1, -1) and is_mas(r + 1, c - 1, -1, 1)
            ) or (
                # Backward diagonal (bottom-right to top-left) + Reverse diagonal (top-right to bottom-left)
                is_mas(r + 1, c + 1, -1, -1) and is_mas(r - 1, c + 1, 1, -1)
            ):
                count += 1

    return count


example_grid = [list(input()) for _ in range(11)]

# Convert to list of lists
example_grid = [list(row) for row in example_grid]

# Count X-MAS patterns
result = count_xmas(example_grid)
print(result)
