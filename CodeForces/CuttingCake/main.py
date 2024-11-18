
for _ in range(int(input())):
    n, m, v = map(int, input().split())

    a = list(map(int, input().split()))

    pref = [0]
    for i in range(n):
        pref.append(pref[-1] + a[i])
    
    inds_front = {}
    inds_front[0] = -1
    cur = 0
    for i in range(n):
        cur += a[i]
        if cur >= v:
            cur = 0
            inds_front[len(inds_front)] = i
        
    
    
    inds_back = {}
    inds_back[0] = n
    cur = 0
    for i in range(n-1, -1, -1):
        cur += a[i]
        if cur >= v:
            cur = 0
            inds_back[len(inds_back)] = i
    
    ans = -1
    for num in inds_front:
        if m - num in inds_back:
            ind1 = inds_front[num]
            ind2 = inds_back[m - num]
            if ind1 < ind2:
                ans = max(ans, pref[ind2] - pref[ind1 + 1])
    
    print(ans)




    

