from math import ceil
inp = open("race.in", 'r')
out = open("race.out", 'w')

k, n = map(int, inp.readline().split())

for _ in range(n):
    x = int(inp.readline())
    
    dist = 0
    speed = 1
    ans = 10000000000
    t = 0
    while dist < k:
        t += 1

        dist += speed
        if speed < x:
            speed += 1
        else:
            cur = (k - dist) / ((x + speed) / 2)
            ans = min(ans, t + int(cur))

    if ans > t:
        ans = t
    print(ans, file=out)


