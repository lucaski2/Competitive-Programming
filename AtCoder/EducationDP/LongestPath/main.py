from collections import deque


n, m = map(int, input().split())
graph = [[] for _ in range(n)]
nums = {i:0 for i in range(n)}

for _ in range(m):
    x, y = map(int, input().split())
    graph[x-1].append(y-1)
    nums[y-1] += 1
memo = [0 for _ in range(n)]

while nums:
    start = [key for key in nums if all(nums[temp] >= nums[key] for temp in nums)][0]
    q = deque([start])
    del nums[start]
    while q:
        cur = q.popleft()
        
        for nxt in graph[cur]:
            if memo[nxt] < memo[cur] + 1:
                memo[nxt] = memo[cur] + 1
                q.append(nxt)
                if nxt in nums:
                    del nums[nxt]


print(max(memo))




