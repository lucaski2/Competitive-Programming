from collections import deque

inp = open("blist.in", "r")
out = open("blist.out", "w")
N = int(inp.readline().strip())
info = [tuple(map(int, inp.readline().strip().split())) for _ in range(N)]
info.sort(key=lambda x: x[0])
current_used = 0
longest = 0
ends = deque()

for i in range(N):
    while len(ends) > 0 and info[i][0] > ends[0][0]:
        last = ends.popleft()
        current_used -= last[1]
        print(i)
        print(last)
    
    current_used += info[i][2]
    
    ends.append((info[i][1], info[i][2]))
    ends = deque(sorted(ends))
    if current_used > longest:
        longest = current_used


print(longest, file=out)