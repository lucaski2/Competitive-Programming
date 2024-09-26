
n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()


cur_amount = k + 1
ans = 0
for i in range(1, n):
    diff = a[i] - a[i - 1]
    if k >= diff:
        cur_amount += diff
    else:
        ans += cur_amount
        cur_amount = k + 1
ans += cur_amount
print(ans)




