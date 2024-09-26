n = int(input())
a = list(map(int, input().split()))
progs = []
cur = []
for i in range(n):
    if i == 0 or i == 1 or a[i] - a[i - 1] == a[i - 1] - a[i - 2]:
        cur.append(a[i])
    else:
        if len(cur) == 2:
            progs.append(1)
            cur = [a[i - 1], a[i]]
        else:
            progs.append(len(cur))
            cur = [a[i - 1], a[i]]
progs.append(len(cur))
ans = 0
for prog in progs:
    ans += (prog + 1) * (prog) // 2
    print(ans)
print(progs)
print(ans + len(progs) - 1)
    

