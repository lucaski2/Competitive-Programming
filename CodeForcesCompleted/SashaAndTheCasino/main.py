
for _ in range(int(input())):
    k, x, a = map(int, input().split())
    s = 1
    for _ in range(x):
        l, r = 0, 1000000000
        while l < r:
            mid = (l + r) // 2
            if mid * k > s + mid:
                r = mid
            else:
                l = mid + 1
        s += l
        # print(l)
    if s - 1 < a:
        print("YES")
    else:
        print("NO")
