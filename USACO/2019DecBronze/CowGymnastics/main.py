
k, n = map(int, input().split())

grid = [list(map(int, input().split())) for _ in range(k)]
s = set()
for i in range(n):
    for j in range(n):
        if i == j:
            continue
        for a in range(1, k):
            if grid[a].index(i + 1) - grid[a].index(j + 1) > 0 and grid[a - 1].index(i + 1) - grid[a - 1].index(j + 1) < 0:
                break
            if grid[a].index(i + 1) - grid[a].index(j + 1) < 0 and grid[a - 1].index(i + 1) - grid[a - 1].index(j + 1) > 0:
                break

        else:
            s.add((min(i, j), max(i, j)))

print(len(s))
