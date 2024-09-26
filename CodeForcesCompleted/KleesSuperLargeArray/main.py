
for _ in range(int(input())):
    n, k = map(int, input().split())
    
    ans = 100000000000000
    left, right = 1, n
    while left <= right:
        mid = (left + right) // 2
        cur = (n + k - 1 + k) * n // 2
        cur *= -1
        cur += (k + mid + k - 1) * mid
        ans = min(ans, abs(cur))
        if cur < 0:
            left = mid + 1
        else:
            right = mid - 1
        
    print(ans)