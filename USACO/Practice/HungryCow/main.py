
n, t = map(int, input().split())

shipments = [tuple(map(int, input().split())) for _ in range(n)]

eaten = 0
cur_hay = shipments[0][1]

for i in range(1, n):
    if cur_hay < shipments[i][0] - shipments[i - 1][0]:
        eaten += cur_hay
        cur_hay = 0
    else:
        cur_hay -= shipments[i][0] - shipments[i - 1][0]
        eaten += shipments[i][0] - shipments[i - 1][0]
    cur_hay += shipments[i][1]

eaten += min(cur_hay, t + 1 - shipments[-1][0])

print(eaten)

