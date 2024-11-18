
from heapq import heappop, heappush
INF = 10**18

def dijkstra(graph, start, horses):
    dists = [[INF, INF] for _ in range(len(graph))]
    dists[start][0] = 0

    heap = [(0, start, 0)]
    visited = [[False, False] for _ in range(len(graph))]
    while heap:
        dist, node, horse = heappop(heap)
        if visited[node][horse]:
            continue
        visited[node][horse] = True

        horse |= horses[node]

        for neighbor, weight in graph[node]:
            am = dist + weight // 2 * (2 - horse)
            if dists[neighbor][horse] > am:
                dists[neighbor][horse] = am
                heappush(heap, (dists[neighbor][horse], neighbor, horse))
    
    return dists
        


for _ in range(int(input())):
    n, m, h = map(int, input().split())

    hor = list(map(int, input().split()))
    horses = [0] * n
    for i in hor:
        horses[i - 1] = 1
    
    graph = [[] for _ in range(n)]
    for i in range(m):
        u, v, w = map(int, input().split())
        u -= 1
        v -= 1
        graph[u].append((v, w))
        graph[v].append((u, w))

    ans = INF
    d1 = dijkstra(graph, 0, horses)
    d2 = dijkstra(graph, n - 1, horses)

    for i in range(n):
        ans = min(ans, max(min(d1[i]), min(d2[i])))
    print(ans if ans != INF else -1)

        
    







