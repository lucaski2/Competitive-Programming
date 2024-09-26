from collections import deque


for _ in range(int(input())):
    n = int(input())
    grid = [list(input()) for _ in range(2)]
    visited = set()
    q = deque()
    q.append((0, 0))
    visited.add((0,))
    
    while q:
        x, y = q.popleft()
        if x == 1 and y == n - 1:
            print("YES")
            break

        possible = [(x + 1, y), (x, y + 1), (x - 1, y), (x, y - 1)]
        for pos in possible:
            if 0 <= pos[0] < 2 and 0 <= pos[1] < n:
                offset = -1 if grid[pos[0]][pos[1]] == "<" else 1
                new_pos = (pos[0], pos[1] + offset)
                if new_pos not in visited and 0 <= new_pos[0] < 2 and 0 <= new_pos[1] < n:
                    visited.add(new_pos)
                    q.append(new_pos)
        

    else:
        print("NO")






