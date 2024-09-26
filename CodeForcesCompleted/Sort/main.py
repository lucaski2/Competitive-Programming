
for _ in range(int(input())):
    n, q = map(int, input().split())
    a = list(input())
    b = list(input())
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    pref_sum = [[0 for _ in range(26)]]
    
    cur_s = [0 for _ in range(26)]
    
    for i in range(n):
        cur_s[alphabet.index(a[i])] += 1
        cur_s[alphabet.index(b[i])] -= 1
        pref_sum.append(cur_s.copy())
    for _ in range(q):
        l, r = map(int, input().split())
        l -= 1
        r -= 1
        l_list = pref_sum[l]
        r_list = pref_sum[r + 1]
        # print(r_list, l_list)
        diff = [r_list[i] - l_list[i] for i in range(26)]
        s1 = 0
        s2 = 0
        for d in diff:
            if d > 0:
                s1 += d
            elif d < 0:
                s2 -= d
        # print(diff)
        print(min(s1, s2) + abs(s1 - s2))

