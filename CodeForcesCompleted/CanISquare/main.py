

for _ in range(int(input())):
    n = int(input())
    a = sum(list(map(int, input().split())))
    print("YES" if pow(a, 0.5).is_integer() else "NO")

