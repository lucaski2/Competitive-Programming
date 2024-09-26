from heapq import heappop, heappush, heapify


h, w, y = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(h)]
heap = [(grid[i][j], (i, j)) for i in range(h) for j in range(w) if i == 0 or j == 0 or j == w - 1 or i == h - 1]
heapify(heap) 
visited = set([(i, j) for i in range(h) for j in range(w) if i == 0 or j == 0 or j == w - 1 or i == h - 1])
floating = h * w

for height in range(1, y + 1):

    while heap and heap[0][0] <= height:
        _, (i, j) = heappop(heap)
        indexes_around = []
        
        if i > 0 and (i - 1, j) not in visited:
            indexes_around.append((i - 1, j))
        if i < len(grid) - 1 and (i + 1, j) not in visited:
            indexes_around.append((i + 1, j))
        if j > 0 and (i, j - 1) not in visited:
            indexes_around.append((i, j - 1))
        if j < len(grid[0]) - 1 and (i, j + 1) not in visited:
            indexes_around.append((i, j + 1))
        for x, y in indexes_around:
            heappush(heap, (grid[x][y], (x, y)))
            visited.add((x, y))
        floating -= 1
    print(floating)





