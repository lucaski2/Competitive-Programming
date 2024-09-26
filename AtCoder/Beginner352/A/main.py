
n, x, y, z = map(int, input().split())

if z in range(min(x, y), max(x, y) + 1):
    print("Yes")
else:
    print("No")