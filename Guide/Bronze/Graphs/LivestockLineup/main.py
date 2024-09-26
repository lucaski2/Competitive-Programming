COWS = list(sorted(["Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"]))

inp = open("lineup.in", "r")
out = open("lineup.out", "w")

n = int(inp.readline())

graph = {COWS[i]:[] for i in range(8)}

connected_components = []

cur_keys = {}
in_components = {COWS[i]:0 for i in range(8)}

for _ in range(n):
	cur_inp = inp.readline().strip().split()
	graph[cur_inp[0]].append(cur_inp[-1])
	graph[cur_inp[-1]].append(cur_inp[0])
	cur_keys[cur_inp[0]] = 1
	cur_keys[cur_inp[-1]] = 1
	in_components[cur_inp[0]] = 1
	in_components[cur_inp[-1]] = 1



def dfs(node, graph, visited, components):
	visited.add(node)
	del cur_keys[node]
	components.append(node)

	for neighbor in graph[node]:
		if not neighbor in visited:
			dfs(neighbor, graph, visited, components)
	return components



visited = set()
cnt = 0
while len(cur_keys) > 0:
	connected_components.append(dfs(str(next(iter(cur_keys))), graph, visited, []))
	if cnt > 5:
		break
	cnt += 1

for i in range(len(connected_components)):
	if connected_components[i][0] > connected_components[i][-1]:
		connected_components[i] = connected_components[i][::-1]

for item in in_components.keys():
	if in_components[item] != 1:
		connected_components.append([item])

connected_components.sort(key = lambda x: x[0])

for i in connected_components:
	for j in i:
		out.write(j + "\n")



