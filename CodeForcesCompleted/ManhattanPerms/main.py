from math import ceil
for _ in range(int(input())):
    n, k = map(int, input().split())
    m = 0
    for i in range(1, n + 1):
        m += abs(n + 1 - i - i)
    if k % 2 == 1 or m < k:
        print("NO")
        continue

    arr = list(range(1, n + 1))
    for i in range(n // 2):
        if k >= (n - 1 - i * 2) * 2:
            k -= (n - 1 - i * 2) * 2
            arr[i], arr[n - 1 - i] = arr[n - 1 - i], arr[i]
        elif k == 0:
            break
        else:
            arr[i], arr[i + k // 2] = arr[i + k // 2], arr[i]
            k = 0

    print("YES")
    print(*arr)