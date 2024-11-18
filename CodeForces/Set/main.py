
for _ in range(int(input())):
    l, r, k = map(int, input().split())

    x = int(r/k)
    print(max(0, x - l + 1))