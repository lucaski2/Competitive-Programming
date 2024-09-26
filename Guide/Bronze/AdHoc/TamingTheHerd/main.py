import random

inp = open("taming.in", "r")
out = open("taming.out", "w")

n = int(inp.readline())
dates = list(map(int, inp.readline().strip().split()))

if dates[0] != 0 and dates[0] != -1:
    print(-1, file=out)
    exit()


breakout_dates = [1] + [0] * (n - 1)
for ind, data in enumerate(dates):
    if data != -1 and data != 0:
        breakout_dates[ind] = 2
        for i in range(ind - 1, ind - data, -1):
            if breakout_dates[i] == 1:
                print(-1, file=out)
                exit()
            breakout_dates[i] = 2
        breakout_dates[ind - data] = 1

    if data == 0:
        breakout_dates[ind] = 1
        




print(breakout_dates.count(1), breakout_dates.count(1) + breakout_dates.count(0), file=out)

# print(breakout_dates.count(1), breakout_dates.count(1) + breakout_dates.count(0))




