
# def binary_search(length_s, target):
#     left = 0
#     right = len(length_s) - 1
#     while left <= right:
#         mid = (left + right) // 2
#         if length_s[mid] >= target and (mid == 0 or length_s[mid - 1] < target):
#             return mid
#         elif length_s[mid] < target:
#             left = mid + 1
#         else:
#             right = mid - 1

    


# for _ in range(int(input())):
#     n, k, q = map(int, input().split())
#     length_s = list(map(int, input().split()))
#     time_s = list(map(int, input().split()))
#     length_s.insert(0, 0)
#     time_s.insert(0, 0)
    
    
#     for __ in range(q):
#         d = int(input())
#         # if _ != 1:
#         #     continue
#         # if d == length_s[-1]:
#         #     # print('asdf')
#         #     print(time_s[-1], end=' ')
#         #     continue

#         cur = binary_search(length_s, d)
#         # print("cur", cur)
#         if cur == 0:
#             print(0, end=' ')
#             continue
#         # print(d, '-', length_s[cur - 1], '/', length_s[cur], '-', length_s[cur - 1])
#         ratio = (d - length_s[cur - 1]) / (length_s[cur] - length_s[cur - 1]) if d > length_s[cur - 1] else 0
#         # print('ratio', ratio)
#         print(int(time_s[cur - 1] + (time_s[cur] - time_s[cur - 1]) * ratio), end=' ')

#     print()
    

def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] > target:
            right = mid - 1
        else:
            left = mid + 1
    return right



for _ in range(int(input())):
    n, k, q = map(int, input().split())
    length_s = [0] + list(map(int, input().split()))
    time_s = [0] + list(map(int, input().split()))
    
    results = []
    for _ in range(q):
        d = int(input())
        r = binary_search(length_s, d)
        if length_s[r] == d:
            results.append(str(time_s[r]))
            continue
        results.append(str(time_s[r] + (time_s[r + 1] - time_s[r]) * (d - length_s[r]) // (length_s[r + 1] - length_s[r])))
    
    print(' '.join(results))