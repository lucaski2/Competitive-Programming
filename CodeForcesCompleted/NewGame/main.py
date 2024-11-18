
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    groups = []
    cur = []

    for i in range(n):
        if not cur or a[i] - cur[-1] == 1 or a[i] - cur[-1] == 0:
            cur.append(a[i])
        else:
            groups.append(cur)
            cur = [a[i]]
    if cur:
        groups.append(cur)
    
    ans = 0

    for group in groups:
        # create prefix sum
        counts = []
        cur = 0
        cur_num = 0
        for i in range(len(group)):
            if i == 0:
                cur_num = group[i]
                cur += 1
                continue
            if group[i] == cur_num:
                cur += 1
            else:
                counts.append(cur)
                cur_num = group[i]
                cur = 1
        
        counts.append(cur)
        # print(counts)

        pref = [0]
        for i in range(len(counts)):
            pref.append(pref[-1] + counts[i])
        
        for i in range(min(len(counts) - 1, k), len(counts) + 1):
            ans = max(ans, pref[i] - pref[max(0, i - k)])
        
        


        
    print(ans)
        

