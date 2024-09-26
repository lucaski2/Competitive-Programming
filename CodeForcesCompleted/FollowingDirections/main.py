for _ in range(int(input())):
    n = int(input())
    s = list(input())
    for i in range(n):
        if s[i] == 'U':
            s[i] = (0, 1)
        elif s[i] == 'D':
            s[i] = (0, -1)
        elif s[i] == 'L':
            s[i] = (-1, 0)
        elif s[i] == 'R':
            s[i] = (1, 0)
    # print(s)
    cur = [0, 0]
    for i in range(n):
        cur[0] += s[i][0]
        cur[1] += s[i][1]
        if cur == [1, 1]:
            print("YES")
            break
        # print(cur)
    else:
        print("NO")
