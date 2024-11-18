
n, k, q = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
for j in range(k):
    for i in range(1, n):
        grid[i][j] |= grid[i - 1][j]

for _ in range(q):
    m = int(input())
    glob_l = 0
    glob_r = n - 1
    ok = True
    for __ in range(m):
        r, c, am_water = input().split()
        am_water = int(am_water)
        r = int(r) - 1
        
        if c == '>':
            cur_l = glob_l
            cur_r = glob_r
            ans = -1
            while cur_l <= cur_r:
                mid = (cur_l + cur_r) // 2
                if grid[mid][r] <= am_water:
                    cur_l = mid + 1
                else:
                    cur_r = mid - 1
                    ans = mid

            if ans == -1:
                ok = False
            else:
                glob_l = ans
        else:
            cur_l = glob_l
            cur_r = glob_r
            ans = -1
            while cur_l <= cur_r:
                mid = (cur_l + cur_r) // 2
                if grid[mid][r] >= am_water:
                    cur_r = mid - 1
                else:
                    cur_l = mid + 1
                    ans = mid
            if ans == -1:
                ok = False
            else:
                glob_r = ans
    

    if ok:
        print(glob_l + 1)
    else:
        print(-1)