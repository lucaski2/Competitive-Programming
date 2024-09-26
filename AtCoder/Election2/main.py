a, b, c = map(int, input().split())
c, b = min(b, c), max(b, c)
c += a - b - c
if b > c:
    print("Yes")
else:
    print("No")