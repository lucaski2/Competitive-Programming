
for _ in range(int(input())):
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    # if _ != 0:
    #     continue
    for i in range(n - 1):
        if a[i] < a[i + 1] - k:
            m -= a[i + 1] - k - a[i]
        else:
            m += min(a[i], max(0, a[i] - a[i + 1] + k))
        if m < 0:
            print("NO")
            break
        # print(m)

        
    else:
        print("YES")