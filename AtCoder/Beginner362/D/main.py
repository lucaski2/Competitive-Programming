from heapq import heappop
from heapq import heappush

def shortest_path(graph, vertex_weights):
    n = len(graph)
    dist = [float('inf')] * n
    dist[0] = vertex_weights[0]
    visited = [False] * n
    
    pq = [(vertex_weights[0], 0)]

    while pq:
        current_distance, current_node = heappop(pq)

        if visited[current_node]:
            continue
        
        visited[current_node] = True

        for neighbor, weight in graph[current_node]:
            distance = current_distance + weight + vertex_weights[neighbor]

            if distance < dist[neighbor]:
                dist[neighbor] = distance
                heappush(pq, (distance, neighbor))

    return dist




n, m = map(int, input().split())
vertex_weights = list(map(int, input().split()))
# create adjaency matrix
graph = [[] for _ in range(n)]

for i in range(m):
    u, v, w = map(int, input().split())
    graph[u-1].append((v-1, w))
    graph[v-1].append((u-1, w))



solution = shortest_path(graph, vertex_weights)
for i in range(1, n):
    print(solution[i], end=' ')
print()







