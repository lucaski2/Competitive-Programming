from collections import deque



def get_adjacent_in_grid(g, i, j):
    adjacent = []
    if i > 0:
        adjacent.append(g[i-1][j])
    if i < len(g) - 1:
        adjacent.append(g[i+1][j])
    if j > 0:
        adjacent.append(g[i][j-1])
    if j < len(g[i]) - 1:
        adjacent.append(g[i][j+1])
    return adjacent

def get_adjacent_indexes_grid(g, i, j):
    adjacent = []
    if i > 0:
        adjacent.append((i-1, j))
    if i < len(g) - 1:
        adjacent.append((i+1, j))
    if j > 0:
        adjacent.append((i, j-1))
    if j < len(g[i]) - 1:
        adjacent.append((i, j+1))
    return adjacent


h, w = map(int, input().split())

grid = [input() for _ in range(h)]

possible_starts = set()

for i in range(len(grid)):
    for j in range(len(grid[i])):
        if "#" not in get_adjacent_in_grid(grid, i, j) and grid[i][j] != "#":
            possible_starts.add((i, j))

s = 1


while len(possible_starts) > 0:
    start = possible_starts.pop()
    component = set()
    component.add(start)
    queue = deque([start])

    while len(queue) > 0:

        cur = queue.popleft()
        adjacents = get_adjacent_in_grid(grid, cur[0], cur[1])
        if "#" in adjacents:
            continue
        
        for adj in get_adjacent_indexes_grid(grid, cur[0], cur[1]):
            if adj not in component:
                queue.append(adj)
                component.add(adj)
                possible_starts.discard(adj)

    s = max(s, len(component))

        
print(s)







