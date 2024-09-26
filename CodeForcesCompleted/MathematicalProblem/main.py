
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, list(input())))
    m = 100000000000000000000
    for i in range(n - 1):
        lst = []
        for j in range(n):
            if j == i:
                continue
            elif j == i + 1:
                lst.append(int(str(a[i]) + str(a[j])))
            else:
                lst.append(a[j])
        if 0 in lst:
            print(0)
            break

        cur = lst[0]
        for j in range(1, len(lst)):
            if cur == 1 or lst[j] == 1:
                cur *= lst[j]
            else:
                cur += lst[j]
        m = min(cur, m)
        # print(lst)

    else:
        print(m)

    # break