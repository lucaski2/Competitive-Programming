
for _ in range(int(input())):
    n, m = map(int, input().split())

    second_mex = []
    for i in range(n):
        a = list(map(int, input().split()))
        a = a[1:]
        a = list(set(a))
        a.sort()
        cur_diffs = 0
        a.insert(0, -1)
        for i in range(1, len(a)):
            if cur_diffs == 0 and a[i] - a[i - 1] - 1 >= 2:
                second_mex.append(a[i - 1] + 2)
                break
            if a[i] - a[i - 1] > 1:
                cur_diffs += a[i] - a[i - 1] - 1
            if cur_diffs > 1:
                second_mex.append(a[i - 1] + 1)
                break
        else:
            second_mex.append(a[-1] + 2 - cur_diffs)

        
    am = max(second_mex)
    am_m = am * min(am + 1, m + 1)
    m -= min(am, m)
    # if m == 0:
    #     print(am)
    #     continue
    ans = am_m + (am + 1 + am + m) * m // 2
    print(ans)