
for _ in range(int(input())):
    x, y, z = map(int, input().split())
    ans = 0
    while x * y > z:
        x -= 1
        ans += 1
    print(ans)