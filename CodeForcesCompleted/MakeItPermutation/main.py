
for _ in range(int(input())):
    n, c, d = map(int, input().split())
    a = list(map(int, input().split()))
    # if _ != 0:
    #     continue
    s = set()
    new_a = []
    cost = 0
    for i in range(len(a)):
        if a[i] in s:
            cost += c
        else:
            s.add(a[i])
            new_a.append(a[i])

    a = new_a
    if 1 not in a:
        cost += d
        a.insert(0, 1)

    n = len(a)
    a.sort()

    ans = 1000000000000000000
    total_gaps = 0
    for i in range(n - 1):
        total_gaps += (a[i + 1] - a[i] - 1)
    

    for i in range(n - 1, -1, -1):
        ans = min(total_gaps * d + (n - i - 1) * c, ans)
        total_gaps -= (a[i] - a[i - 1] - 1)
    # print(ans, cost, total_gaps, a)
    print(ans + cost)






