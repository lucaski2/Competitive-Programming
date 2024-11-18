
for _ in range(int(input())):

    l, r = 0, 10**5
    cur = 10000000
    for i in range(70):
        # get left
    
        print("P", l, 10**5, flush=True)
        response = float(input())
        print("P", r, 10**5, flush=True)
        response2 = float(input())
    
        if response < response2:
            r = (l + r) / 2
            cur = response
        else:
            l = (l + r) / 2
            cur = response2
    print("B", l, cur, flush=True)

    
