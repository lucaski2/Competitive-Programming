
n, t = map(int, input().split())

times = [list(map(int, input().split())) for _ in range(n)]
times.append([t + 1, 0])
n += 1
ans = 0
am = 0
am = times[0][1]
for i in range(1, n):
    time = times[i][0] - times[i - 1][0]
    # print(time, am, end=' ')
    if time > am:
        ans += am
        am = 0
    else:
        am -= time
        ans += time
    am += times[i][1]
    # print(am)

print(ans)