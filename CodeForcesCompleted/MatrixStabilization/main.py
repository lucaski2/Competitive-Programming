def greater_than_elements_around(grid, row, col, num_rows, num_cols):
  """
  This function finds elements greater than the current element in the surrounding cells.

  Args:
      grid: A 2D list representing the grid.
      row: The row index of the current element.
      col: The column index of the current element.
      num_rows: The total number of rows in the grid.
      num_cols: The total number of columns in the grid.

  Returns:
      A list containing elements greater than the current element from surrounding cells.
  """
  neighbors = []
  if 0 <= row - 1 < num_rows:  # Check for valid row index above
    neighbors.append(grid[row - 1][col])
  if 0 <= row + 1 < num_rows:  # Check for valid row index below
    neighbors.append(grid[row + 1][col])
  if 0 <= col - 1 < num_cols:  # Check for valid column index left
    neighbors.append(grid[row][col - 1])
  if 0 <= col + 1 < num_cols:  # Check for valid column index right
    neighbors.append(grid[row][col + 1])
  return neighbors

def main():
  num_test_cases = int(input())
  for _ in range(num_test_cases):
    num_rows, num_cols = map(int, input().split())
    grid = [[int(x) for x in input().split()] for _ in range(num_rows)]

    for row in range(num_rows):
      for col in range(num_cols):
        neighbors = greater_than_elements_around(grid, row, col, num_rows, num_cols)
        if neighbors and grid[row][col] > max(neighbors):
          grid[row][col] = max(neighbors)

    for row in grid:
      print(*row)  # Print each row with spaces

if __name__ == "__main__":
  main()
