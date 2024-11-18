
from collections import deque


for _ in range(int(input())):
    n, m, s = map(int, input().split())

    graph = [[] for _ in range(n)]
    num_pointing = [0] * n
    for _ in range(m):
        u, v = map(int, input().split())
        graph[u - 1].append(v - 1)
        num_pointing[v - 1] += 1
    
    cur_layer = deque()
    next_layer = deque()
    visited = [False] * n

    num_visited = 0


    for i in range(n):
        if num_pointing[i] == 0:
            cur_layer.append(i)
            visited[i] = True
            num_visited += 1
    ans = 100000000000
    m = None
    while num_visited < n:
        cur = cur_layer.popleft()

        for neighbor in graph[cur]:
            if not visited[neighbor]:
                next_layer.append(neighbor)
                visited[neighbor] = True
                num_visited += 1

        if len(cur_layer) == 0:
            if len(next_layer) < ans:
                ans = len(next_layer)
                m = list(next_layer)
            cur_layer = next_layer
            next_layer = deque()
    
    if ans > s:
        print("IMPOSSIBLE")
    else:
        print(*[i + 1 for i in m])





    

