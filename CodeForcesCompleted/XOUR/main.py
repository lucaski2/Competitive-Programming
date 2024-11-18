
for _ in range(int(input())):
    n = int(input())
    temp = list(map(int, input().split()))
    
    a = [[0, 0] for i in range(n)]
    for i in range(n):
        # strip of last 2 bits
        a[i][0] = temp[i] >> 2
        a[i][1] = temp[i]
    
    groups = {}
    for i in range(n):
        if a[i][0] not in groups:
            groups[a[i][0]] = [[], []]
        groups[a[i][0]][0].append(a[i][1])
        groups[a[i][0]][1].append(i)
    
    ans = [-1] * n
    groups = list(groups.values())
    for i in range(len(groups)):
        groups[i][0].sort()
        for j in range(len(groups[i][0])):
            ans[groups[i][1][j]] = groups[i][0][j]
    
    print(*ans)

    

