
n = int(input())

x_l = dict()
y_l = dict()

for i in range(n):
    x, y = map(int, input().split())
    if x in x_l:
        x_l[x].append((y, i))
    else:
        x_l[x] = [(y, i)]
    if y in y_l:
        y_l[y].append((x, i))
    else:
        y_l[y] = [(x, i)]

for k in x_l.keys():
    x_l[k].sort()
for k in y_l.keys():
    y_l[k].sort()

graph = [[] for _ in range(n)]
x_l = x_l.items()
y_l = y_l.items()

for x in x_l:
    for i in range(len(x[1]) - 1):
        c1, c2 = x[1][i][1], x[1][i + 1][1]
        graph[c1].append(c2)
        graph[c2].append(c1)
for x in y_l:
    for i in range(len(x[1]) - 1):
        c1, c2 = x[1][i][1], x[1][i + 1][1]
        graph[c1].append(c2)
        graph[c2].append(c1)

for i in range(n):
    graph[i] = list(set(graph[i]))

nodes = set(range(n))
def dfs(node, nodes):
    for i in graph[node]:
        if i in nodes:
            nodes.remove(i)
            dfs(i, nodes)

ans = 0
while nodes:
    ans += 1
    dfs(nodes.pop(), nodes)

print(ans - 1)











