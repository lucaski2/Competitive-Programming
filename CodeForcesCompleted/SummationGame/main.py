
for _ in range(int(input())):
    n, k, x = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    pref_sum = [0]
    for i in range(n):
        pref_sum.append(pref_sum[-1] + a[i])
    
    s = sum(a)
    m = -float('inf')
    for i in range(n - k - 1, n):
        ind1, ind2 = i - x, i
        if ind1 < 0:
            m = max(m, -pref_sum[i + 1])
        else:
            m = max(m, s - (pref_sum[-1] - pref_sum[i + 1]) - 2 * (pref_sum[i + 1] - pref_sum[ind1 + 1]))
    print(m)



