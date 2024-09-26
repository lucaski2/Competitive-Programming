
for _ in range(int(input())):
    n = int(input())
    a = list(input())
    b = set(input().split()[1:])

    for j in b:
        if j in a:
            break
    else:
        print(0)
        continue

    end = []
    for i in range(n):
        if i != n - 1 and a[i + 1] not in b:
            end.append(a[i])
        if i == n - 1:
            end.append(a[i])
    
    if a == end:
        print(0)
        continue

    m_gap = 0
    cur = 0
    for i in range(len(end)):
        if end[i] in b:
            m_gap = max(m_gap, cur)
            cur = 1
        else:
            cur += 1
    print(m_gap + 1)



    
    # print("".join(end))






