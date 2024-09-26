
n, p = map(int, input().split())
posts = [tuple(map(int, input().split())) for _ in range(p)]
points = {}
cur = 0
for i in range(p):
    p1, p2 = posts[i], posts[i + 1 if i + 1 < p else 0]
    # print(points)
    if p1[0] == p2[0]:
        for i in range(p1[1], p2[1], -1 if p1[1] > p2[1] else 1):
            points[(p1[0], i)] = cur
            cur += 1
    else:
        for i in range(p1[0], p2[0], -1 if p1[0] > p2[0] else 1):
            points[(i, p1[1])] = cur
            cur += 1
    

# print(points)
for _ in range(n):
    a = tuple(map(int, input().split()))
    a, b = a[:2], a[2:]
    print(min(abs(points[a] - points[b]), cur - abs(points[a] - points[b])))

    
