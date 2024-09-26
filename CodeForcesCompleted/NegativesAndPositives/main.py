
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    
    num = 0
    for i in range(n):
        if a[i] < 0:
            num += 1
        num %= 2
    
    for i in range(n):
        a[i] = abs(a[i])
    s = sum(a)
    if num:
        print(s - 2 * min(a))
    else:
        print(s)
