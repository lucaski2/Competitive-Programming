n = int(input())
ranges = [list(map(int, input().split())) for _ in range(n)]

m = 0
m2 = 0
for x, y in ranges:
    m += x
    m2 += y
if m <= 0 and m2 >= 0:
    print("Yes")
else:
    print("No")
    exit()

amount = -m

for i in range(n):
    if ranges[i][1] - ranges[i][0] >= amount:
        print(ranges[i][0] + amount, end=" ")
        amount = 0
    else:
        print(ranges[i][1], end=" ")
        amount -= ranges[i][1] - ranges[i][0]
print()
