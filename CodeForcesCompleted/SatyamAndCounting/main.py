
for _ in range(int(input())):
    n = int(input())
    points = [list(map(int, input().split())) for i in range(n)]
    points_d_x = {}
    points_d_y = {}
    points_s = set()
    for i in range(n):
        x, y = points[i]
        points_s.add((x, y))
        if x in points_d_x:
            points_d_x[x] += 1
        else:
            points_d_x[x] = 1
        if y in points_d_y:
            points_d_y[y] += 1
        else:
            points_d_y[y] = 1
    ans = 0
    for i in range(n):
        x, y = points[i]
        ans += (points_d_x[x] - 1) * (points_d_y[y] - 1)
        if y == 0 and (x + 1, 1) in points_s and (x - 1, 1) in points_s:
            ans += 1
        if y == 1 and (x + 1, 0) in points_s and (x - 1, 0) in points_s:
            ans += 1
    print(ans)