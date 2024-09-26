
for _ in range(int(input())):
    n, m = map(int, input().split())
    if n < m:
        print(-1)
        continue
    print(n + 1)