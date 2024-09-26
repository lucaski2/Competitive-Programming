
import math


n = int(input())
ans = 0
a = [n]
while a:
    cur = a.pop()
    ans += cur
    a1 = cur // 2
    a2 = math.ceil(cur / 2)

    if a1 >= 2:
        a.append(a1)
    if a2 >= 2:
        a.append(a2)

print(ans)



