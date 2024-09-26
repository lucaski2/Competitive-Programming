def distance(x1, y1, x2, y2):
    return (abs(x1 - x2) ** 2 + abs(y1 - y2) ** 2)

for _ in range(int(input())):
    n = int(input())
    a = [list(map(int, input().split())) for _ in range(n)]
    startx, starty, endx, endy = map(int, input().split())
    dist = distance(startx, starty, endx, endy)
    for i in range(n):
        if distance(endx, endy, a[i][0], a[i][1]) <= dist:
            print("NO")
            break
    else:
        print("YES")
            