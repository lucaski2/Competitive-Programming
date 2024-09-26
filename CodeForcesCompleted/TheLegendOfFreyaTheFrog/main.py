from math import ceil
for _ in range(int(input())):
    x, y, k = map(int, input().split())
    print(max(ceil(x / k), ceil(y / k)) * 2 - 1 if ceil(x / k) > ceil(y / k) else ceil(y / k) * 2)
