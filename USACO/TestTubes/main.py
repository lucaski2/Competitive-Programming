
def f(type, tube, tube_conts, other):
    recon = []

    last = None
    used = False
    while tube_conts:
        cont = tube_conts.pop()
        if last != cont and last != None:
            if last != other:
                recon.append(f"{tube} 3")
                used = True
            else:
                recon.append(f"{tube} {3 - tube}")
        last = cont
    if used:
        if last != other:
            recon.append(f"{tube} 3")
        else:
            recon.append(f"{tube} {3 - tube}")
        
        recon.append(f"3 {tube}")
    return recon, len(recon)


for _ in range(int(input())):
    n, k = map(int, input().split())
    tube1 = list(map(int, list(input())))
    tube2 = list(map(int, list(input())))

    if len(set(tube1)) == 1 and len(set(tube2)) == 1:
        print(0)
        continue
    elif len(set(tube1)) == 1:
        ans = f(k, 2, tube2, tube1[0])
    elif len(set(tube2)) == 1:
        ans = f(k, 1, tube1, tube2[0])
    else:
        s = f(k, 1, tube1.copy(), tube2[0])
        s2 = f(k, 2, tube2.copy(), tube1[0])
        ans = s[0] + s2[0], s[1] + s2[1]



    print(ans[1])
    if k >= 2:
        print("\n".join(ans[0]))        

