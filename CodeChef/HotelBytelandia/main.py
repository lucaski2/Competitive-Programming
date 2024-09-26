from heapq import heappush, heappop


for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a = [[a[i], b[i]] for i in range(n)]
    ans = 0
    heap = []
    a.sort()
    for i in range(n):
        while heap and heap[0] <= a[i][0]:
            heappop(heap)
        heappush(heap, a[i][1])
        ans = max(ans, len(heap))
    print(ans)
