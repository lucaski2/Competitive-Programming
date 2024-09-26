
from collections import deque

for _ in range(int(input())):
    n, m = map(int, input().split())
    grid = [list(input()) for _ in range(n)]
    
    visited = [[False] * m for _ in range(n)]
    rows = [0] * n
    cols = [0] * m

    for i in range(n):
        for j in range(m):
            if grid[i][j] == '.':
                continue
            if not visited[i][j]:
                q = deque([(i, j)])
                visited[i][j] = True
                size = 0
                min_x, min_y, max_x, max_y = i, j, i, j
                while q:
                    x, y = q.popleft()
                    size += 1
                    for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                        nx, ny = x + dx, y + dy
                        if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == '#' and not visited[nx][ny]:
                            visited[nx][ny] = True
                            q.append((nx, ny))
                            min_x = min(min_x, nx)
                            min_y = min(min_y, ny)
                            max_x = max(max_x, nx)
                            max_y = max(max_y, ny)
                for x in range(max(0, min_x - 1), min(n, max_x + 2)):
                    rows[x] += size
                for y in range(max(0, min_y - 1), min(m, max_y + 2)):
                    cols[y] += size
    
    ans = 0
    for row in range(n):
        ans = max(ans, rows[row] + grid[row].count('.'))
    grid2 = list(zip(*grid))
    for col in range(m):
        ans = max(ans, cols[col] + grid2[col].count('.'))

    print(ans)


