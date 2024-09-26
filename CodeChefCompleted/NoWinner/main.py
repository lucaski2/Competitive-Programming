for _ in range(int(input())):
    a, b, c, m = map(int, input().split())
    if abs(b - c) <= m or abs(b - a) <= m or abs(c - a) <= m:
        print("YES")
    else:
        print("NO")