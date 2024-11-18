from math import ceil
for _ in range(int(input())):
    n = int(input())
    x, y = map(int, input().split())
    if x >= y:
        print(ceil(n / y))
    else:
        print(ceil(n / x))