from collections import deque

n, m = map(int, input().split())

q = [n]
lengths = {n:0}
p = 0

while q:
    # print(q)
    cur = q[p]
    if cur == m:
        print(lengths[cur])
        break
    p += 1

    combs = [cur - 1, cur * 2]

    for comb in combs:
        if comb <= 0 or comb > max(n, m) * 2 or comb in lengths:
            continue
        q.append(comb)
        lengths[comb] = lengths[cur] + 1







