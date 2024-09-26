from collections import deque


class Elements:
    def __init__(self):
        self.n, self.m = map(int, input().split())
        self.edges = []
        self.graph = [[] for _ in range(self.n)]
        for _ in range(self.m):
            u, v = map(int, input().split())
            u -= 1
            v -= 1
            self.edges.append((u, v))
            self.graph[u].append(v)
            self.graph[v].append(u)

        self.visited = [False] * self.n
        self.lowest = [INF] * self.n
        self.parent = [-1] * self.n
        self.depths = [INF] * self.n
        self.bridges = set()

    def recursive_dfs(self, node, parent):
        self.visited[node] = True
        if parent == -1:
            self.depths[node] = 0
        else:
            self.depths[node] = self.depths[parent] + 1

        self.lowest[node] = self.depths[node]

        for child in self.graph[node]:
            if not self.visited[child]:
                self.parent[child] = node
                self.recursive_dfs(child, node)
                self.lowest[node] = min(self.lowest[node], self.lowest[child])
            elif child != parent:
                self.lowest[node] = min(self.lowest[node], self.depths[child])

    def find_bridges(self):
        self.recursive_dfs(0, -1)

        for edge in self.edges:
            u, v = edge
            if self.depths[u] > self.depths[v]:
                u, v = v, u
            
            if self.lowest[v] > self.depths[u]:
                self.bridges.add(edge)

    def compress_graph(self):
        self.find_bridges()
        not_visited = set(range(self.n))
        
        m_to_component = {}
        count = 0 
        while not_visited:
            node = not_visited.pop()
            q = deque([node])
            cur_comp = []

            while q:
                node = q.popleft()
                not_visited.discard(node)
                cur_comp.append(node)

                for neighbor in self.graph[node]:
                    if (node, neighbor) in self.bridges or (neighbor, node) in self.bridges:
                        continue
                    if neighbor in not_visited:
                        q.append(neighbor)
            
            for node in cur_comp:
                m_to_component[node] = count

            count += 1
        
        compressed_graph = [[] for _ in range(count)]
        for u, v in self.bridges:
            u = m_to_component[u]
            v = m_to_component[v]
            compressed_graph[u].append(v)
            compressed_graph[v].append(u)
        
        q = deque([0])
        visited = [False] * count
        depths = [0] * count

        while q:
            node = q.popleft()
            visited[node] = True
            for neighbor in compressed_graph[node]:
                if not visited[neighbor]:
                    q.append(neighbor)
                    depths[neighbor] = depths[node] + 1
            
        q = deque([depths.index(max(depths))])

        visited = [False] * count
        depths = [0] * count
        while q:
            node = q.popleft()
            visited[node] = True
            for neighbor in compressed_graph[node]:
                if not visited[neighbor]:
                    q.append(neighbor)
                    depths[neighbor] = depths[node] + 1
        
        return max(depths)

elements = Elements()
print(elements.compress_graph())
