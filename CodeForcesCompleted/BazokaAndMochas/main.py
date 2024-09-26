
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    if a == list(sorted(a)):
        print("YES")
        continue
    for i in range(n):
        cur = a[i:]
        cur2 = a[:i]
        if cur + cur2 == list(sorted(cur + cur2)):
            print("YES")
            break
    else:
        print("NO")