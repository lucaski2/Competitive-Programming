

for _ in range(int(input())):
    n, d, h = map(int, input().split())
    a = list(map(int, input().split()))
    # if _ != 2:
    #     continue
    a.reverse()
    # print(a)
    cur = 0
    slope = h / d * 2
    slope = 1 / slope
    # print(slope)
    for i in range(n):
        # print(cur)

        if i == 0 or a[i - 1] - a[i] >= h:
            cur += d * h / 2
            continue

        cur_b = d - (a[i - 1] - a[i]) * slope * 2
        
        cur += (cur_b + d) / 2 * (a[i - 1] - a[i])
        
    print(cur)


