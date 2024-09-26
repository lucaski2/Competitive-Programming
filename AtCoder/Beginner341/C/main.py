
h, w, n = map(int, input().split())
directions = list(input())

grid = [list(input()) for _ in range(h)]


ans = 0
for i in range(h):
    for j in range(w):
        cur_pos = [i, j]
        ind = 0

        while ind < n and grid[cur_pos[0]][cur_pos[1]] != '#':
            if directions[ind] == 'U':
                cur_pos[0] -= 1
            elif directions[ind] == 'D':
                cur_pos[0] += 1
            elif directions[ind] == 'L':
                cur_pos[1] -= 1
            elif directions[ind] == 'R':
                cur_pos[1] += 1
            ind += 1
        if grid[cur_pos[0]][cur_pos[1]] == '.':
            ans += 1
print(ans)