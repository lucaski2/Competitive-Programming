n, m = map(int, input().split())

pairs = [tuple(map(int, input().split())) for _ in range(m)]

graph = [set() for _ in range(n)]
list_graph = [[] for _ in range(n)]

for pair in pairs:
    graph[pair[0] - 1].add(pair[1] - 1)
    graph[pair[1] - 1].add(pair[0] - 1)
    list_graph[pair[0] - 1].append(pair[1] - 1)
    list_graph[pair[1] - 1].append(pair[0] - 1)

s = 0
for neighbors in list_graph:
    for i in range(len(neighbors)):
        for j in range(i + 1, len(neighbors)):
            if neighbors[i] not in graph[neighbors[j]]:
                graph[neighbors[i]].add(neighbors[j])
                graph[neighbors[j]].add(neighbors[i])
                list_graph[neighbors[i]].append(neighbors[j])
                list_graph[neighbors[j]].append(neighbors[i])
    
                s += 1

print(s)


