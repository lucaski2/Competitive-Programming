n, a, b = map(int, input().split())
lst = list(map(int, input().split()))
ranges = []

for i in range(n):
    lst[i] = lst[i] % (a+b)
    ranges.append([-lst[i], a - lst[i]])
rg = [0, a + b]
for i in range(n):
    rg[0] = max(rg[0], ranges[i][0])
    rg[1] = min(rg[1], ranges[i][1])
if rg[0] > rg[1]:
    print("No")
else:
    print("Yes")






