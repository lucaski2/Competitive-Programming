from collections import deque
def dist(x1, y1, x2, y2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2)**0.5

inp = open('moocast.in', 'r')
out = open('moocast.out', 'w')

n = int(inp.readline())

cows = [list(map(int, inp.readline().split())) for _ in range(n)]

graph = [[] for _ in range(n)]

for i in range(n):
    for j in range(n):
        if i == j:
            continue
        if dist(cows[i][0], cows[i][1], cows[j][0], cows[j][1]) <= cows[i][2]:
            graph[i].append(j)
print(graph)
ans = 0
for i in range(n):
    visited = [False] * n
    q = deque([i])
    visited[i] = True
    while q:
        node = q.popleft()
        for neighbor in graph[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                q.append(neighbor)
    ans = max(ans, sum(visited))

out.write(str(ans) + '\n')




