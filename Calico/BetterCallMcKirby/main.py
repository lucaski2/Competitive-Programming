
for _ in range(int(input())):
    b, n = list(map(int, input().split()))
    a = list(map(int, input().split()))

    l = 0
    r = 10**25
    ans = 10**25
    min_danger = 10**25
    min_cost = 10**25
    while l + 1 < r:
        m = (l + r) // 2
        danger = 0
        cost = 0
        for i in range(n):
            if a[i] < m:
                danger += m - a[i]
            else:
                cost += a[i] - m
        # print(m, danger, cost)
        if cost > b:
            l = m
        else:
            if danger < min_danger:
                min_danger = danger
                min_cost = cost
                ans = m
                r = m
            elif danger == min_danger:
                if cost < min_cost:
                    min_cost = cost
                    ans = m
                    l = m 
                else:
                    r = m
            else:
                r = m
            

    

    print(ans)

