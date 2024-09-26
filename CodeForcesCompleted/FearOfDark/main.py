
def distance(x1, x2, y1, y2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

for _ in range(int(input())):
    px, py = map(int, input().split())
    ax, ay = map(int, input().split())
    bx, by = map(int, input().split())
    d1 = min(max(distance(ax, px, ay, py), distance(ax, 0, ay, 0)), max(distance(bx, px, by, py), distance(bx, 0, by, 0)))
    d2 = max([distance(ax, bx, ay, by) / 2, distance(ax, 0, ay, 0), distance(bx, px, by, py)])
    d3 = max([distance(ax, bx, ay, by) / 2, distance(bx, 0, by, 0), distance(ax, px, ay, py)])
    print(min(d1, d2, d3))
