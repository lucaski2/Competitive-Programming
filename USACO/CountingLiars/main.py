
n = int(input())
g = []
l = []
for i in range(n):
    ty, a = input().split()
    if ty == 'G':
        g.append(int(a))
    else:
        l.append(int(a))

g.sort()
l.sort()
m = 0
for i, num in enumerate(g):
    ans = i + 1
    for j in range(len(l)):
        if l[j] >= num:
            ans += 1
    m = max(m, ans)
print(n - m)