from math import log10, floor, log2, ceil


n = int(input())
adj = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    adj[a - 1].append(b - 1)
    adj[b - 1].append(a - 1)

amounts = [0] * n
visited = [False] * n
count = 0

def dfs(node):
    global count
    visited[node] = True

    children = 0
    for neighbor in adj[node]:
        if not visited[neighbor]:
            children += 1
    
    if children == 0:
        return 0
    
    days = ceil(log2(children + 1))
    count += days
    for neighbor in adj[node]:
        if not visited[neighbor]:
            count += 1
            dfs(neighbor)

    

dfs(0)
print(count)
            


