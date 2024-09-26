from math import ceil
def binary_search(start, end, cur_s, mult, x):
    
    while start < end:
        mid = (start + end) // 2
        if mid * mult - cur_s <= x and (mid + 1) * mult - cur_s > x:
            return mid
        elif mid * mult - cur_s >= x:
            end = mid
        else:
            start = mid + 1
    return start

for _ in range(int(input())):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    cur_s = a[0]
    start = 0

    for i in range(1, n):
        if i * a[i] - cur_s > x:
            start = i - 1
            break
        cur_s += a[i]
    else:
        start = n - 1
    am = binary_search(a[start], 10**18, cur_s, start + 1, x)
    print(am)
