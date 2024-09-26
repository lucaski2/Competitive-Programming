import bisect

n = int(input())
coords = list(map(int, input().split()))
people = list(map(int, input().split()))

p_sum = [0]
for p in people:
    p_sum.append(p + p_sum[-1])

q = int(input())

for _ in range(q):
    l, r = map(int, input().split())
    ind1 = bisect.bisect_left(coords, l)
    ind2 = bisect.bisect_right(coords, r)
    print(p_sum[ind2] - p_sum[ind1])
