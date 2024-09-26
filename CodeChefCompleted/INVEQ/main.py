for _ in range(int(input())):
    n = int(input())
    st = list(map(int, list(input())))
    last = st[0]
    ams = [0, 0]

    for i in range(1, n):
        if st[i] != last and st[i] == 1:
            ams[0] += 1
        elif st[i] != last and st[i] == 0:
            ams[1] += 1


    
    
        if i == n-1:
            if st[i] == 1:
                ams[1] += 1
            else:
                ams[0] += 1


        last = st[i]
    
    print(min(ams))
