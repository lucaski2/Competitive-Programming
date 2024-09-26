from heapq import heappush, heappop


for _ in range(int(input())):
    h, n = map(int, input().split())
    damages = list(map(int, input().split()))
    cooldowns = list(map(int, input().split()))
    h -= sum(damages)
    heap = []
    cur_time = 1
    for i in range(n):
        heappush(heap, (cooldowns[i] + 1, i))
    while h > 0:
        cur = heappop(heap)
        h -= damages[cur[1]]
        cur_time = cur[0]
        heappush(heap, (cur_time + cooldowns[cur[1]], cur[-1]))
        while heap[0][0] == cur[0]:
            cur = heappop(heap)
            h -= damages[cur[1]]
            heappush(heap, (cur_time + cooldowns[cur[1]], cur[-1]))

    print(cur_time)
        

