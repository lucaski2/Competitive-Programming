
n, m = map(int, input().split())

g = [input() for _ in range(n)]

lengths = set()

def solve(grid, popcorn_eaten, visited_vendors, num_visited):
    if False not in popcorn_eaten:
        lengths.add(num_visited)
        return
    if False not in visited_vendors:
        return

    for i in range(n):
        if visited_vendors[i]:
            continue

        new_popcorn_eaten = popcorn_eaten.copy()
        for j in range(m):
            if grid[i][j] == "o":
                new_popcorn_eaten[j] = True
        new_thing = visited_vendors.copy()
        new_thing[i] = True
        solve(grid, new_popcorn_eaten, new_thing, num_visited + 1)
    
solve(g, [False] * m, [False] * n, 0)
print(min(lengths))





