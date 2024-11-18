
n = int(input())

a = list(map(int, input().split()))


ans = []
earliest = 0
for i in range(32):

    cur = None
    cur_ans = []
    for j in range(n):
        if a[j] & (1 << i):
            if cur is None:
                cur = a[j]
                cur_ans.append(cur)
            else:
                cur &= a[j]
                cur_ans.append(a[j])

    if cur is not None:
        if (cur & -cur) > (earliest & -earliest):
            earliest = cur
            ans = cur_ans

print(len(ans))
print(*ans)

