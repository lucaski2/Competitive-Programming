
n, m = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(n)]

arr.sort(key=lambda x: x[0])

ans = 0

lowest = []
for i in range(n - 1, -1, -1):
    if lowest:
        lowest.append(min(lowest[-1], arr[i][1]))
    else:
        lowest.append(arr[i][1])

s = set()
for i in range(n - 1):
    if arr[i][0] in s:
        continue
    s.add(arr[i][0])
    dist = arr[i][0] - lowest[i] - 1
    ans += dist * (dist + 1) // 2

dist = arr[0][0] - 1
ans += dist * (dist + 1) // 2
dist = m - lowest[-1] - 1
ans += dist * (dist + 1) // 2

print(ans)

