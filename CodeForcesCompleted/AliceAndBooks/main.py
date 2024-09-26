
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    lst = [0, 0]
    for i in range(n):
        if lst[0] <= lst[1]:
            lst[0] = a[i]
        else:
            lst[1] = a[i]
    print(sum(lst))