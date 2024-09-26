
n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
# turn adjacency matrix into adjacency list
adj_list = [[] for _ in range(n)]
for i in range(n):
    for j in range(n):
        if graph[i][j] == 1:
            adj_list[i].append(j + 1)

for i in range(len(adj_list)):
    adj_list[i].sort()  # sort the neighbors in ascending order
    print(*adj_list[i])

