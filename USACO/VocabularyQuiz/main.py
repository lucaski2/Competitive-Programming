N = int(input())

words = list(map(int, input().split()))
graph = [[] for _ in range(N + 1)]
depths = [0 for _ in range(N + 1)]

for i, word in enumerate(words, start=1):
    graph[word].append(i)

parent_of = {}
for parent, children in enumerate(graph):
    for child in children:
        parent_of[child] = parent


leaf_count = sum(1 for x in graph if x == [])
remaining_leaves = leaf_count
# ok so we for each node, we need to find the first node that has >= 2 children, and the ans is the depth of that node + 1
# we need to do this for each node, and then we need to find the minimum depth
# this approach should always account for the case where the ans is 1, and we can simpily have a counter to check for the last node (since the ans for that is 0)
# so for this we can probably just use a while loop to find the first node that has >= 2 children, and then we can use a counter to find the depth of that node + 1

def dfs_from_leaf(node, visited):

    while node != 0 and len(graph[node]) < 2:
        node = parent_of[node]

    return node

def create_depths(cur, depth):
  depths[cur] = depth
  for neighbor in graph[cur]:
      create_depths(neighbor, depth + 1)


    
create_depths(0, 0)

for t in range(leaf_count):
    remove_node = int(input())
    visited = set()

    if remaining_leaves == 1:
        print(0)
    else:
        print(depths[(dfs_from_leaf(remove_node, visited))] + 1)
    
    cur = remove_node

    

    remaining_leaves -= 1

