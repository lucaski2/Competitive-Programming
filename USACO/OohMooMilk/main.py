from heapq import heappush, heappop, heapify
n, d = map(int, input().split())

a, b = map(int, input().split())

ams = list(map(int, input().split()))
# make max heap
for i in range(n):
    ams[i] = -ams[i]
heapify(ams)

rems = []
for i in range(a):
    rems.append(-heappop(ams))

for i in range(a):
    heappush(ams, -rems[i] - d)

elements = []
for ele in ams:
    elements.append(-ele)

elements.sort()
elements.reverse()

am = b * d
start = 0
for i in range(b):
    if (elements[i] - d > elements[b]):
        am -= d
        elements[i] -= d
        start += 1

psum = [0] * (n + 1)


for i in range(n):
    psum[i + 1] = psum[i] + elements[i]

best = 0
for i in range(start, n):
    psum_am = psum[i] - psum[start]
    psum_am -= (i - start) * elements[i]
    if (psum_am >= am):
        break
    best = i

for i in range(start, best + 1):
    diff = elements[i] - elements[best]
    am -= diff
    elements[i] = elements[best]

dec = best - start + 1
start_am = am
for i in range(start, best + 1):
    am -= start_am // dec
    elements[i] -= start_am // dec

for i in range(start, best):
    if (am > 0):
        am -= 1
        elements[i] -= 1
ans = 0
mod = 10 ** 9 + 7
for i in range(n):
    ans += elements[i] * elements[i]
    ans %= mod
print(ans % mod)



