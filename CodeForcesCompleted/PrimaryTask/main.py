from math import log10

for _ in range(int(input())):
    n = input()
    if len(n) <= 2:
        print("NO")
        continue
    if n[:2] != '10':
        print("NO")
        continue
    n = n[2:]
    if n[0] == '0':
        print("NO")
        continue
    if int(n) >= 2:
        print("YES")
        continue
    else:
        print("NO")

