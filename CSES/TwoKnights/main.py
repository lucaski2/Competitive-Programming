from math import comb

n = int(input())
last = 0
for i in range(1, n + 1):
    cur = comb(i * i, 2)
    if i > 2:
        cur -= (i - 2) * (i - 1) * 4
    print(cur)


