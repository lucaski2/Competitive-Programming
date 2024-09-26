from math import ceil

for _ in range(int(input())):
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    s = {}

    for i in list(sorted(a))[:ceil(k / m)]:
        if i in s:
            s[i] += 1
        else:
            s[i] = 1
    ma = max(s.keys())
    offset = 0
    total = 0
    for i in range(n):
        if a[i] in s and s[a[i]] > 0:
            s[a[i]] -= 1
            if ma == a[i] and k % m != 0:
                total += (a[i] + offset) * (k % m)
                offset += k % m
                ma = None
                
            else:
                total += (a[i] + offset) * m
                offset += m

    print(total)
    