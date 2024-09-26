from collections import deque
import copy

def get_nodes_around(grid, i, j):
    nodes_around = []
    for x, y in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
        if 0 <= x < len(grid) and 0 <= y < len(grid[0]):
            nodes_around.append((x, y))
    return nodes_around


h, w = map(int, input().split())

grid = [list(input()) for _ in range(h)]

n = int(input())

for i in range(h):
    for j in range(w):
        if grid[i][j] == "S":
            start = (i, j)
        grid[i][j] = [grid[i][j], 0]

for i in range(n):
    r, c, e = map(int, input().split())
    grid[r - 1][c - 1] = [grid[r - 1][c - 1], e]


q = deque([start])

visited = set()
mins = []

while q:
    x, y = q.popleft()
    visited.add((x, y))
    if grid[x][y][0] == "T":
        continue

    nodes = get_nodes_around(grid, x, y)

    for node in nodes:
        if node in visited:
            continue
        nx, ny = node
        if grid[nx][ny][0] == "#":
            continue
        if grid[nx][ny][0] == "T":
            mins.append(grid[x][y][1] + 1)
        else:
            grid[nx][ny][1] = grid[x][y][1] + 1
            q.append(node)
    




    













