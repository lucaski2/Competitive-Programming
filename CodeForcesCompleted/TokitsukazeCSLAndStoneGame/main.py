n = int(input())
a = list(map(int, input().split()))

a.sort()
d = {}
for i in range(n):
    if a[i] not in d:
        d[a[i]] = 1
    else:
        d[a[i]] += 1

c = 0
ind = -1
for it, val in d.items():
    if val > 1:
        if c > 0:
            print("cslnb")
            exit()
        ind = it
        c += 1
        if val > 2:
            print("cslnb")
            exit()
if ind - 1 in d:
    print("cslnb")
    exit()

if n > 1 and a[0] == 0 and a[1] == 0:
    print("cslnb")
    exit()

turns = 0

if c != 0:
    turns += 1
    a[a.index(it)] -= 1

lowest = 0 if a[0] != 0 else 1

for i in range(n):
    if a[i] == 0 and i == 0:
        continue
    turns += a[i] - lowest
    lowest += 1

print("sjfnb" if turns % 2 == 1 else "cslnb")



