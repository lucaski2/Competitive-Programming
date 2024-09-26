
for _ in range(int(input())):
    
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    b_counts = {}
    current = {}

    for i in range(m):
        if b[i] in b_counts:
            b_counts[b[i]] += 1
        else:
            b_counts[b[i]] = 1
    
    for num in b_counts.keys():
        current[num] = 0
    
    current_amount = 0
    
    for i in range(m):
        if a[i] in current:
            current[a[i]] += 1
    
    for i in current.keys():
        current_amount += min(current[i], b_counts[i])
    
    ans = 1 if current_amount >= k else 0
    for i in range(m, n):
        cur_removing = a[i - m]
        cur_adding = a[i]
        if cur_removing in b_counts:
            current[cur_removing] -= 1
            current_amount -= 1 if current[cur_removing] < b_counts[cur_removing] else 0
        if cur_adding in b_counts:
            current[cur_adding] += 1
            current_amount += 1 if current[cur_adding] <= b_counts[cur_adding] else 0
        if current_amount >= k:
            ans += 1
    print(ans)
