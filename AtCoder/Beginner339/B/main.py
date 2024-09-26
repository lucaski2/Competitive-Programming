
h, w, n = map(int, input().split())
grid = [list("." * w) for _ in range(h)]
cur_dir = [-1, 0]
cur_pos = [0, 0]
for _ in range(n):
    if grid[cur_pos[0]][cur_pos[1]] == ".":
        grid[cur_pos[0]][cur_pos[1]] = "#"
        # change cur_dir clockwise
        cur_dir = [cur_dir[1], -cur_dir[0]]

    else:
        grid[cur_pos[0]][cur_pos[1]] = "."
        # change cur_dir counter-clockwise
        cur_dir = [-cur_dir[1], cur_dir[0]]
    
    cur_pos[0] += cur_dir[0]
    cur_pos[1] += cur_dir[1]
    if cur_pos[0] < 0:
        cur_pos[0] = h - 1
    elif cur_pos[0] >= h:
        cur_pos[0] = 0
    elif cur_pos[1] < 0:
        cur_pos[1] = w - 1
    elif cur_pos[1] >= w:
        cur_pos[1] = 0
for i in range(h):
    print("".join(grid[i]))




