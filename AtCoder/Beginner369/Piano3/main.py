
last_r = None
last_l = None
q = int(input())
ans = 0
for i in range(q):
    n, ty = input().split()
    n = int(n)
    if ty == 'L':
        if last_l is None:
            last_l = n
        else:
            ans += abs(n - last_l)
            last_l = n
    elif ty == 'R':
        if last_r is None:
            last_r = n
        else:
            ans += abs(n - last_r)
            last_r = n
print(ans)