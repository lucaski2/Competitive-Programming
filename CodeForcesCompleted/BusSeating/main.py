
for _ in range(int(input())):
    n = int(input())
    lst = [False for _ in range(n)]
    a = list(map(int, input().split()))
    for i in range(n):
        cur = a[i] - 1
        lst[cur] = True
        if i == 0:
            continue
        if cur != 0 and lst[cur - 1]:
            continue
        if cur != n - 1 and lst[cur + 1]:
            continue
        
        print("NO")
        break
    else:
        print("YES")