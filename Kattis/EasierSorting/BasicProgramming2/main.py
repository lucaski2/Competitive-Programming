N, t = list(map(int, input().split()))
lst = list(map(int, input().split()))

lst = sorted(lst)

if t == 1:
    res_dct = {lst[i]: i for i in range(len(lst))}
    for val in res_dct.keys():
        try:
            res_dct[7777 - val]
            print("Yes")
            break
        except:
            pass
    else:
        print("No")

if t == 2:
    if list(set(lst)) == lst:
        print("Unique")
    else:
        print("Contains duplicate")


if t == 3:
    count = {}
    for i in lst:
        if i in count:
            count[i] += 1
        else:
            count[i] = 1
    mx = max(count.values())
    if mx >= N / 2:
        for key, val in count.items():
            if val == mx:
                print(key)
                break

    else:
        print(-1)

if t == 4:

    if N % 2 == 0:
        print(lst[N // 2 - 1], lst[N // 2])
    else:
        print(lst[N // 2])


if t == 5:
    
    for i in range(N):
        if lst[i] >= 100 and lst[i] <= 999:
            print(lst[i], end=" ")
        
        if lst[i] > 999:
            break
    print()