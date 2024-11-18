
for _ in range(int(input())):
    n, k, d = map(int, input().split())
    a = list(map(int, input().split()))
    # if _ != 1:
    #     continue
    ans = 0

    for _ in range(k):
        pref = [0] * (n + 1)
        nearest_zero = [0] * (n + 1)
        for i in range(n):
            pref[i + 1] = pref[i] + a[i]
            if a[i] == 0:
                nearest_zero[i + 1] = i
                pref[i + 1] = 0
                i += 
            else:
                nearest_zero[i + 1] = nearest_zero[i]
        best = 0
        best_end = []
        for i in range(0, n + 1):
            am = pref[i] - pref[max(i - d, 1 + nearest_zero[i])]
            # print(pref[i], pref[max(i - d, 1 + nearest_zero[i])])
            if am > best:
                best = am
                best_end = [i, max(i - d, 1 + nearest_zero[i])]
        
        if not best:
            break
        ans += best
        for i in range(best_end[1], best_end[0]):
            a[i] = 0

    print(ans)
