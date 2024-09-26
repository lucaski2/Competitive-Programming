
n = int(input())
amounts = list(map(int, input().split()))

k = int(input())
temp = [list(map(int, input().split())) for _ in range(k)]
graph = [[] for _ in range(n)]
temp.sort()

for i in range(k):
    cur = int(temp[i][0]) - 1
    for j in range(temp[i][1]):
        graph[cur].append(temp[i][j + 2] - 1)


for i in range(n):
    graph[i].sort(reverse=True)
done = False
while not done:
    cur = n - 1
    while True:
        if len(graph[cur]) == 0:
            done = True
            break
        for neigh in graph[cur]:
            if amounts[neigh] <= 0:
                cur = neigh
                break
        else:
            amounts[cur] += 1
            for neigh in graph[cur]:
                amounts[neigh] -= 1
            break

print(amounts[-1])


