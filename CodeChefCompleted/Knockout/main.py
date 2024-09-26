
for _ in range(int(input())):
    s = list(map(int, input().split()))
    sorted_s = list(sorted(s))
    # print(sorted_s)
    for i in range(16):
        # if i != 11:
        #     continue
        cur_s = sorted_s.copy()
        cur = s[i]
        cur_s.remove(cur)
        ind = 0
        # print(cur)
        for j in range(4):            
            # print(ind, cur_s[ind])
            if cur_s[ind] > cur:
                print(j, end=' ')
                break
            ind += 2**(j+1)
        else:
            print(4, end=' ')
        # break
        # print(cur_s)
    print()


