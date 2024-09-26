
for _ in range(int(input())):
    a, b = map(int, input().split())
    
    # try odds
    cur = b - 1
    cur2 = (b - 1) * 2
    if a - cur > 0 and (a - cur) % 2 == 1:
        print("YES")
        print("1 " * cur + str(a - cur))
    
    elif a - cur2 > 0 and (a - cur2) % 2 == 0:
        print("YES")
        print("2 " * (b - 1) + str(a - cur2))
    else:
        print("NO")

