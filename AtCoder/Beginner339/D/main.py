from collections import deque

n = int(input())

grid = [list(input()) for _ in range(n)]
for i in range(n):
    for j in range(n):
        if grid[i][j] == 'P':
            start = (i,j)


q = deque([start])
visited = set([start])
depth = {start:0}

while q:
    x, y = q.popleft()
    if grid[x][y] == "P" and (x, y) not in visited:
        print(depth[(x, y)])
        break
    visited.add((x, y))

    next_squares = []
    for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
        nx, ny = x + dx, y + dy
        if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] != '#':
            next_squares.append((nx, ny))

    for nx, ny in next_squares:
        if (nx, ny) not in visited:
            depth[(nx, ny)] = depth[(x, y)] + 1
            q.append((nx, ny))

else:
    print(-1)



