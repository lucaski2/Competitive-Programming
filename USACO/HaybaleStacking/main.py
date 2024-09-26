

n, k = map(int, input().split())

starts = [0] * (n)
ends = [0] * (n)

for i in range(k):
    a, b = map(int, input().split())
    starts[a - 1] += 1
    ends[b - 1] += 1

counts = [0] * (n)

cur_am = 0
for i in range(n):
    cur_am += starts[i]
    counts[i] = cur_am
    cur_am -= ends[i]

counts.sort()
print(counts[n // 2])


