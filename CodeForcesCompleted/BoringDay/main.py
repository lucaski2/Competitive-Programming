
def binary_search(arr, l, r):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] >= l and arr[mid] <= r:
            return True
        elif arr[mid] < l:
            left = mid + 1
        
        else:
            right = mid - 1
    
    return False




for _ in range(int(input())):
    n, l, r = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 0
    prev_sum = []
    cur_sum = 0

    for i in range(n):
        cur_sum += a[i]
        prev_sum.append(cur_sum)

        if cur_sum >= l and cur_sum <= r:
            ans += 1
            prev_sum = []
            cur_sum = 0
        
        elif cur_sum >= l:
            if binary_search(prev_sum, cur_sum - r, cur_sum - l):
                ans += 1
                prev_sum = []
                cur_sum = 0
    print(ans)







