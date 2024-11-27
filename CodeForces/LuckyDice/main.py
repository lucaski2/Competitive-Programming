
for _ in range(int(input())):
    n, m, k = map(int, input().split())
    
    lowest = 10000000000

    for i in range(1, m + 1):
        am = int(i * n + abs((m // 2 + 0.5 - i) * 2) * k)
        lowest = min(lowest, am)

    
    print(lowest)