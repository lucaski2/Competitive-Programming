
for _ in range(int(input())):
    n, m, k = map(int, input().split())
    w = int(input())
    a = list(map(int, input().split()))
    # if _ != 4:
    #     continue
    dists = []
    corners = [(-1, -1), (-1, m), (n, -1), (n, m)]
    for i in range(n):
        for j in range(m):
            # distance from any of the corners
            cur = float('inf')
            for x, y in corners:
                cur = min(cur, min([abs(i - x), n - k + 1, k]) * min([abs(j - y), m - k + 1, k]))
            dists.append(cur)
    
    dists.sort(reverse=True)
    a.sort(reverse=True)
    s = 0
    # print(dists)
    for i in range(w):
        s += a[i] * min(k * k, dists[i])
        # print(s)
    print(s)

