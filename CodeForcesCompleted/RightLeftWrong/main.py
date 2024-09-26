
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    cur = list(input())
    answers = []
    l, r = 0, n - 1
    while True:
        while l < n and cur[l] != 'L':
            l += 1
        if l == n:
            break
        while r >= 0 and cur[r] != 'R':
            r -= 1
        
        if l > r:
            break
        
        answers.append((l, r))
        l += 1
        r -= 1
    
    pref_sum = [0]
    for i in range(n):
        pref_sum.append(pref_sum[-1] + a[i])
    
    s = 0
    for ans in answers:
        s += pref_sum[ans[1] + 1] - pref_sum[ans[0]]

    print(s)