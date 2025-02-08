import heapq

MOD = 1000000000 + 7

class Info:
    def __init__(self, x, y, am):
        self.x = x
        self.y = y
        self.am = am

    def __lt__(self, other):
        return self.am < other.am  # Reverse for max-heap behavior with heapq (Python uses min-heap by default)


def solve(tc):
    n, m, glob_x = map(int, input().split())
    p, q = map(int, input().split())
    p -= 1  # Convert to 0-based indexing
    q -= 1

    grid = [list(map(int, input().split())) for _ in range(n)]

    strength = grid[p][q]
    visited = [[False] * m for _ in range(n)]
    pq = []

    # Add initial neighbors to priority queue
    if p - 1 >= 0:
        heapq.heappush(pq, Info(p - 1, q, grid[p - 1][q]))
        visited[p - 1][q] = True
    if p + 1 < n:
        heapq.heappush(pq, Info(p + 1, q, grid[p + 1][q]))
        visited[p + 1][q] = True
    if q - 1 >= 0:
        heapq.heappush(pq, Info(p, q - 1, grid[p][q - 1]))
        visited[p][q - 1] = True
    if q + 1 < m:
        heapq.heappush(pq, Info(p, q + 1, grid[p][q + 1]))
        visited[p][q + 1] = True

    visited[p][q] = True

    while pq:
        top = heapq.heappop(pq)
        x, y, am = top.x, top.y, top.am

        if glob_x * am >= strength:
            break

        # Check and push neighbors
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny]:
                visited[nx][ny] = True
                heapq.heappush(pq, Info(nx, ny, grid[nx][ny]))

        strength += am

    print(strength)


if __name__ == "__main__":
    t = 1
    for tc in range(1, t + 1):
        solve(tc)
