
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    d = {}
    for i in range(n):
        if a[i] in d:
            d[a[i]] += 1
        else:
            d[a[i]] = 1
    
    for i in range(n):
        num = a[i]
        if num - k in d:
            if num - k == num:
                if d[num - k] > 1:
                    print("YES")
                    break
                else:
                    continue
            else:
                print("YES")
                break
    else:
        print("NO")
