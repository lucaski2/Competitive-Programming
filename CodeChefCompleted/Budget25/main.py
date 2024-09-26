
for _ in range(int(input())):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    transfer_amount = 0
    ans = 0
    for i in range(n):
        if a[i] >= x:
            transfer_amount += a[i] - x
            a[i] = x
            ans += 1
    a.sort(reverse=True)


    for i in range(n):
        if a[i] < x and transfer_amount >= x - a[i]:
            transfer_amount -= x - a[i]
            a[i] = x
            ans += 1
    print(ans)

        