
for _ in range(int(input())):
    points = {0:1, 1:2, 2:3, 3:4, 4:5, 5:5, 6:4, 7:3, 8:2, 9:1}
    
    grid = [list(input()) for _ in range(10)]
    ans = 0
    for i in range(10):
        for j in range(10):
            if grid[i][j] == "X":
                ans += min(points[i], points[j])
    print(ans)

