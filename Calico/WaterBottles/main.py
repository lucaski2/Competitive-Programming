
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split())) 
    a = [[a[i], i] for i in range(n)]
    a.sort()
    ans = 0
    cur_time = 0
    for i in range(n):
        cur_time += a[i][0]
        ans += cur_time
    i = 0
    while i < n:

        if a[a[i][1]][0] == a[i][0] and a[a[i][1]][1] != a[i][1]:
            # swap them
            a[a[i][1]], a[i] = a[i], a[a[i][1]]
            i -= 1
        i += 1
            
    print(ans)
    print(*[a[i][1] + 1 for i in range(n)])