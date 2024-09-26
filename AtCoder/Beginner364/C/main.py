n, x, y = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
a.sort(reverse=True)
b.sort(reverse=True)
c = 0
am = 0
for i in range(n):
    c += a[i]
    am += 1
    if c > x:
        break

c2 = 0
am2 = 0
for i in range(n):
    c2 += b[i]
    am2 += 1
    if c2 > y:
        break

if am2 > am:
    print(am)
elif am2 < am:
    print(am2)

elif sum(a) <= x and sum(b) <= y:
    print(n)
else:
    print(am)




