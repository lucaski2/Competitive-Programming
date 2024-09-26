
def binary_search(arr, target):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2

        if arr[mid][0] <= target and (mid == len(arr) - 1 or arr[mid + 1][0] > target):
            return mid
        elif arr[mid][0] <= target:
            left = mid + 1
        
        else:
            right = mid - 1
    return -1



n = int(input())

arr = [tuple(map(int, input().split())) for _ in range(n)]
arr.sort(key=lambda x: x[0])

s = 0



for i in range(n):
    s += binary_search(arr, arr[i][1]) - i
print(s)








