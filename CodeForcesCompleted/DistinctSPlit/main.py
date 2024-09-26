
for _ in range(int(input())):
    n = int(input())
    s = list(input())
    cur = set()
    cur2 = set()
    forward = [0]
    back = [0]
    for i in range(n):
        cur.add(s[i])
        cur2.add(s[n - i - 1])
        forward.append(len(cur))
        back.append(len(cur2))
    back.reverse()
    ans = 0
    for i in range(n + 1):
        ans = max(ans, forward[i] + back[i])
    print(ans)




