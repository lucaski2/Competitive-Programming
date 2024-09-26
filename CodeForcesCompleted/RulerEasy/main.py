
for _ in range(int(input())):
    rang = [2, 999]

    while rang[0] != rang[1]:
        cur = (rang[0] + rang[1]) // 2
        print("?", cur, 1, flush=True)
        res = int(input())
        if res <= cur:
            rang[0] = cur + 1
        else:
            rang[1] = cur
    print("!", rang[0], flush=True)
        


