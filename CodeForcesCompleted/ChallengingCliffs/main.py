
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    a.sort()
    min_diff = float('inf')
    min_ind = -1
    for i in range(n - 1):
        diff = a[i + 1] - a[i]
        if diff < min_diff:
            min_diff = diff
            min_ind = i
    for i in range(min_ind, n):
        if i == min_ind + 1:
            continue
        print(a[i], end=' ')
    for i in range(min_ind):
        print(a[i], end=' ')
    print(a[min_ind + 1])


