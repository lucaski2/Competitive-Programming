from collections import deque
import random

inp = open("revegetate.in", "r")
out = open("revegetate.out", "w")

n, m = map(int, inp.readline().strip().split())

preferences = [list(map(int, inp.readline().strip().split())) for _ in range(m)]
# preferences = [(random.randint(1, 100), random.randint(1, 100)) for _ in range(100)]
preference_graph = [[] for _ in range(n)]

for preference in preferences:
    preference_graph[preference[0] - 1].append(preference[1] - 1)
    preference_graph[preference[1] - 1].append(preference[0] - 1)

coloring = [-1] * n

for i in range(n):
    cur = preference_graph[i]

    used_colors = set()
    for j in cur:
        if coloring[j] != -1:
            used_colors.add(coloring[j])
    
    for j in range(1, 5):
        if j not in used_colors:
            coloring[i] = j
            break
    
print("".join(list(map(str, coloring))), file=out)

