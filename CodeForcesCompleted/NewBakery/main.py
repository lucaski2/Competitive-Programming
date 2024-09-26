
for _ in range(int(input())):
    n, a, b = map(int, input().split())
    # if _ != 3:
    #     continue
    if a >= b:
        print(n * a)
        continue

    discounts = min(n, (b - a))
    ans = (n - discounts) * a + (b + b - discounts + 1) * (discounts) // 2
    # print((n - discounts) * a, (b + b - discounts + 1) * discounts // 2)
    print(ans)
    