def naive_solution(G, N, grazings, alibis):
    def noreach(x1, y1, t1, x2, y2, t2):
        
        return (x1-x2)**2 + (y1-y2)**2 > (t2-t1)**2

    innocent_count = 0

    for cx, cy, ct in alibis:
        guilty = True

        for gx, gy, gt in grazings:
            if noreach(gx, gy, gt, cx, cy, ct):
                guilty = False
                break

        if not guilty:
            innocent_count += 1

    return innocent_count

g, n = map(int, input().split())
grazings = [tuple(map(int, input().split())) for _ in range(g)]
alibis = [tuple(map(int, input().split())) for _ in range(n)]
print(naive_solution(g, n, grazings, alibis))