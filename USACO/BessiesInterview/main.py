
from heapq import heappop, heappush, heapify

n, k = map(int, input().split())
a = list(map(int, input().split()))
time = 0
ind = k
times = []
for i in range(k):
    heappush(times, (a[i], i))

for i in range(k, n):
    time = heappop(times)[0]
    



