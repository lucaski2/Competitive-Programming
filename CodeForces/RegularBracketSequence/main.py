
for _ in range(int(input())):
    s = list(input())
    n = len(s)
    if n % 2 != 0:
        print('NO')
        continue
    if s[0] == ')' or s[-1] == '(':
        print('NO')
        continue
    cnt1 = 0
    cnt2 = 0
    cnt3 = 0
    for i in range(n):
        if s[i] == '(':
            cnt1 += 1
        elif s[i] == ')':
            cnt2 += 1
        else:
            cnt3 += 1
        if cnt1 + cnt3 < cnt2:
            print("NO")
            break

    else:
        if cnt1 + cnt3 >= cnt2 and cnt2 + cnt3 >= cnt1:
            print('YES')
        else:
            print('NO')