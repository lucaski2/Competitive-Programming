
n = int(input())

players = [input().split() for _ in range(n)]

players.sort(key=lambda x: x[0])

s = 0
for p in players:
    s += int(p[1])


for i in range(len(players)):
    if i == s % n:
        print(players[i][0])
        break





