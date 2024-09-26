
n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]

xs = sorted(set(x for x, y in points), reverse=True)
ys = sorted(set(y for x, y in points), reverse=True)
xs = list(xs)
ys = list(ys)
print(xs, ys)

already_visited = set()
mx = 0
my = 0
for i in range(len(xs)):
    for j in range(len(ys)):
        cur = []
        for ind, (x, y) in enumerate(points):
            if xs[i] >= x >= mx and ys[j] >= y >= my:
                cur.append(ind)
        
        cur = tuple(cur)
        already_visited.add(cur)

mx = xs[-1]
my = ys[-1]
xs.reverse()
ys.reverse()
for i in range(len(xs)):
    for j in range(len(ys)):
        cur = []
        for ind, (x, y) in enumerate(points):
            if mx >= x >= xs[i] and my >= y >= ys[j]:
                cur.append(ind)
        
        cur = tuple(cur)
        already_visited.add(cur)

my = ys[-1]
xs.reverse()
for i in range(len(xs)):
    for j in range(len(ys)):
        cur = []
        for ind, (x, y) in enumerate(points):
            if mx >= x >= xs[i] and ys[j] >= y >= my:
                cur.append((x, y))
        
        cur = tuple(cur)
        already_visited.add(cur)

mx = xs[-1]
ys.reverse()
for i in range(len(xs)):
    for j in range(len(ys)):
        cur = []
        for ind, (x, y) in enumerate(points):
            if xs[i] >= x >= mx and my >= y >= ys[j]:
                cur.append(ind)
        
        cur = tuple(cur)
        already_visited.add(cur)
my = ys[-1]
ys.reverse()
mx = xs[-1]
xs.reverse()

for i in range(len(xs)):
    for j in range(len(ys)):
        cur = []
        for ind, (x, y) in enumerate(points):
            if xs[i] >= x >= mx and ys[j] >= y >= my:
                cur.append(ind)
        
        cur = tuple(cur)
        already_visited.add(cur)

print(len(already_visited))

