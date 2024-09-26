
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    h = list(map(int, input().split()))
    subarrays = []
    cur = [a[0]]
    for i in range(1, n):
        if h[i - 1] % h[i] != 0:
            subarrays.append(cur)
            cur = [a[i]]
        elif h[i - 1] % h[i] == 0:
            cur.append(a[i])
    subarrays.append(cur)

    ans = 0
    for sub in subarrays:
        pref = [0]
        cur_ind = 0
        for i in range(len(sub)):
            pref.append(pref[-1] + sub[i])

            while pref[-1] - pref[cur_ind] > k:
                cur_ind += 1
            ans = max(ans, i - cur_ind + 1)
    print(ans)
