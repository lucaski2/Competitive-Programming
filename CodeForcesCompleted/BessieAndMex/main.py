
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    cur = 0
    p = []
    used = set()
    for i in range(n):
        if a[i] < 0:
            p.append(-a[i] + cur)
            used.add(-a[i] + cur)
        else:
            p.append(cur)
            used.add(cur)
            while cur in used:
                cur += 1
    print(*p)




    



