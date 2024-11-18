
for _ in range(int(input())):
    n, x, y = map(int, input().split())
    curx = 0
    cury = 0
    s = list(input())
    for __ in range(500):
        for i in range(n):
            if s[i] == 'N':
                cury += 1
            elif s[i] == 'S':
                cury -= 1
            elif s[i] == 'E':
                curx += 1
            else:
                curx -= 1
            if curx == x and cury == y:
                print("YES")
                break
        else:
            continue
        break
    else:
        print("NO")