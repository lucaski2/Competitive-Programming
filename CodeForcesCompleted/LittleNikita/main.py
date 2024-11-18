
for _ in range(int(input())):
    a, b = map(int, input().split())
    print("YES" if a >= b and (a - b) % 2 == 0 else "NO")