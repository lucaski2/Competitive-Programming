
for _ in range(int(input())):
    n, d, k = map(int, input().split())

    starts = [0] * n
    ends = [0] * n

    for i in range(k):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        starts[a] += 1
        ends[b] += 1
    
    am = [0] * n

    cur = 0
    for i in range(n):
        cur += starts[i]
        am[i] = cur
        cur -= ends[i]
    