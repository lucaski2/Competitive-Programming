
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a1 = a[:n]
    a2 = a[n:]
    ad = {}
    ad2 = {}
    for i in range(n):
        if a1[i] in ad:
            ad[a1[i]] += 1
        else:
            ad[a1[i]] = 1
        if a2[i] in ad2:
            ad2[a2[i]] += 1
        else:
            ad2[a2[i]] = 1
    ad = list(sorted(list(ad.items()), key=lambda x: x[1]))
    ad2 = list(sorted(list(ad2.items()), key=lambda x: x[1]))
    ind = len(ad) - 1
    ss1 = []
    ss2 = []
    while len(ss1) < k * 2:
        if ad[ind][1] == 1:
            ss1.append(ad[ind][0])
            ss2.append(ad[ind][0])
            ind -= 1
        elif ad[ind][1] == 2:
            ss1.append(ad[ind][0])
            ss1.append(ad[ind][0])
            ind -= 1
    ind = len(ad2) - 1
    while len(ss2) < k * 2:
        if ad2[ind][1] == 2:
            ss2.append(ad2[ind][0])
            ss2.append(ad2[ind][0])
        ind -= 1
    print(*ss1)
    print(*ss2)



    



