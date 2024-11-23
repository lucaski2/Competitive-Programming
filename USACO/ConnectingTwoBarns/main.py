from collections import deque, defaultdict
import math
import sys
from bisect import bisect_left, bisect_right

input = sys.stdin.read
INF = int(1e10)

def main():
    data = input().split()
    t = int(data[0])
    idx = 1
    results = []

    for _ in range(t):
        n, m = map(int, data[idx:idx+2])
        idx += 2

        graph = defaultdict(list)
        for _ in range(m):
            a, b = map(int, data[idx:idx+2])
            idx += 2
            graph[a - 1].append(b - 1)
            graph[b - 1].append(a - 1)

        components = []
        visited = [False] * n
        start = end = 0

        # Find connected components
        for i in range(n):
            if not visited[i]:
                q = deque([i])
                visited[i] = True
                component = set()

                while q:
                    node = q.popleft()
                    component.add(node)
                    if node == 0:
                        start = len(components)
                    if node == n - 1:
                        end = len(components)
                    
                    for neighbor in graph[node]:
                        if not visited[neighbor]:
                            visited[neighbor] = True
                            q.append(neighbor)

                components.append(sorted(component))  # Keep components sorted

        # Calculate the minimum cost
        ans = INF
        for i, comp in enumerate(components):
            m = INF
            for vertex in comp:
                idx1 = bisect_left(components[start], vertex)
                idx2 = bisect_right(components[start], vertex)

                if idx1 < len(components[start]):
                    m = min(m, (vertex - components[start][idx1]) ** 2)
                if idx2 > 0:
                    m = min(m, (vertex - components[start][idx2 - 1]) ** 2)

            m2 = INF
            for vertex in comp:
                idx1 = bisect_left(components[end], vertex)
                idx2 = bisect_right(components[end], vertex)

                if idx1 < len(components[end]):
                    m2 = min(m2, (vertex - components[end][idx1]) ** 2)
                if idx2 > 0:
                    m2 = min(m2, (vertex - components[end][idx2 - 1]) ** 2)

            ans = min(ans, m + m2)

        results.append(ans)

    sys.stdout.write('\n'.join(map(str, results)) + '\n')


if __name__ == "__main__":
    main()
