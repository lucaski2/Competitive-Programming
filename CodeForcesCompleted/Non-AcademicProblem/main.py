import sys
# sys.setrecursionlimit(10**8)

INF = 10**18


class Elements:
    def __init__(self, n, m):
        self.n = n
        self.m = m
        self.graph = [[] for _ in range(n)]
        self.edges = []
        for _ in range(m):
            u, v = map(int, input().split())
            u -= 1
            v -= 1
            self.graph[u].append(v)
            self.graph[v].append(u)
            self.edges.append((u, v))
        # visited
        self.visited = [False] * n
        # the depths in dfs tree
        self.depths = [-1] * n
        self.depths[0] = 0
        # parent of node in dfs tree
        self.parents = [-1] * n
        # the highest node that can be reached from a subtree
        self.highest = [INF] * n
        # the sum of the elements in the subtree
        self.sum_under = [0] * n


def dfs(elements, cur_node):
    # tarjan's algorithm
    # check off visited

    # elements.visited[cur_node] = True
    # elements.highest[cur_node] = elements.depths[cur_node]
    # cur_s = 0
    # for neighbor in elements.graph[cur_node]:
    #     if not elements.visited[neighbor]:
    #         # set parent
    #         elements.parents[neighbor] = cur_node
    #         # set depth
    #         elements.depths[neighbor] = elements.depths[cur_node] + 1
    #         # call dfs on neighbor
    #         dfs(elements, neighbor)

    #         elements.highest[cur_node] = min(elements.highest[cur_node], elements.highest[neighbor])

    #         cur_s += elements.sum_under[neighbor]
    #     elif neighbor != elements.parents[cur_node]:
    #         elements.highest[cur_node] = min(elements.highest[cur_node], elements.depths[neighbor])
    
    # elements.sum_under[cur_node] = cur_s + 1

    # try iterative dfs

    # keep the node and the parent
    stack = [(cur_node, -1)]
    stack2 = []
    while stack:
        cur_node, parent = stack.pop()

        if not elements.visited[cur_node]:
            elements.visited[cur_node] = True
            elements.highest[cur_node] = elements.depths[cur_node]
            elements.parents[cur_node] = parent
            stack2.append(cur_node)

            for neighbor in elements.graph[cur_node]:
                if not elements.visited[neighbor]:
                    stack.append((neighbor, cur_node))
                    elements.depths[neighbor] = elements.depths[cur_node] + 1
                elif neighbor != parent:
                    elements.highest[cur_node] = min(elements.highest[cur_node], elements.depths[neighbor])
    
    while stack2:
        cur_node = stack2.pop()
        cur_s = 0
        for neighbor in elements.graph[cur_node]:
            if elements.parents[neighbor] == cur_node:
                cur_s += elements.sum_under[neighbor]
                elements.highest[cur_node] = min(elements.highest[cur_node], elements.highest[neighbor])
        elements.sum_under[cur_node] = cur_s + 1

    




for _ in range(int(input())):
    n, m = map(int, input().split())
    els = Elements(n, m)
    dfs(els, 0)
    # print(els.depths)
    # print(els.highest)
    ans = (n - 1) * n // 2
    count = 0
    for u, v in els.edges:
        if els.depths[u] > els.depths[v]:
            u, v = v, u
        if els.highest[v] > els.depths[u]:
            cur_am = (els.sum_under[v] - 1) * (els.sum_under[v]) // 2 + (n - els.sum_under[v] - 1) * (n - els.sum_under[v]) // 2
            ans = min(ans, cur_am)
    print(ans)


