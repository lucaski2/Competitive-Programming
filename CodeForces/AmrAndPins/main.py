from math import ceil
r, x, y, x2, y2 = map(int, input().split())

dist = ((x2 - x) ** 2 + (y2 - y) ** 2) ** 0.5
print(ceil(dist / (2 * r)))

