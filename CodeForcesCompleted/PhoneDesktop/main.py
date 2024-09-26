
for _ in range(int(input())):
    
    x, y = map(int, input().split())

    cnt = 0

    while x > 0 or y > 0:
        if y >= 2:
            x -= 7
        elif y == 1:
            x -= 11
        else:
            x -= 15
        y -= 2
        cnt += 1
    
    print(cnt)

