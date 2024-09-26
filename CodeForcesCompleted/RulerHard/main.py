
for _ in range(int(input())):
    rang = [2, 999]
    while rang[1] - rang[0] > 2:
        mid2 = rang[1] - (rang[1] - rang[0]) // 3
        mid1 = rang[0] + (rang[1] - rang[0]) // 3
        print('?', mid1, mid2, flush=True)
        x = int(input())
        if x == (mid1 + 1) * (mid2 + 1):
            rang[1] = mid1
        elif x == mid1 * mid2:
            rang[0] = mid2 + 1
        else:
            rang[0] = mid1 + 1
            rang[1] = mid2
    if rang[0] == 0:
        print('!', rang[0], flush=True)
    elif rang[0] == 1:
        print("?", rang[0], rang[1], flush=True)
        inp = int(input())
        if inp == (rang[0] + 1) * (rang[1] + 1):
            print('!', rang[0], flush=True)
        else:
            print('!', rang[1], flush=True)
    else:
        print("?", rang[0], rang[0] + 1, flush=True)
        inp = int(input())
        if inp == rang[0] * (rang[0] + 1):
            print('!', rang[1], flush=True)
        elif inp == (rang[0] + 1) * (rang[0] + 2):
            print('!', rang[0], flush=True)
        else:
            print('!', rang[0] + 1, flush=True)
        
