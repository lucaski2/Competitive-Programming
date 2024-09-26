
def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return arr[mid]
        elif arr[mid] <= target:
            left = mid + 1
        
        else:
            right = mid - 1
    
    return arr[left]
    



for _ in range(int(input())):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    # if _ != 4:
    #     continue
    petal_groupings = []
    petal_counts = {}
    for i in range(n):
        if a[i] in petal_counts:
            petal_counts[a[i]] += 1
        else:
            petal_counts[a[i]] = 1
    
    items = list(petal_counts.items())
    items.sort(key=lambda x: x[0])
    for i in range(len(items)):
        if (i == 0 and (len(items) == 1 or items[i][0] != items[i + 1][0] + 1)) or items[i][0] != items[i - 1][0] + 1:
            petal_groupings.append([items[i][0]] * items[i][1])
        else:
            petal_groupings.append([items[i - 1][0]] * items[i - 1][1] + [items[i][0]] * items[i][1])

    ans = 0
    # print(petal_groupings)
    
    for grouping in petal_groupings:
        local_max = 0
        cur_sum = [0]
        for i in range(len(grouping)):
            cur_sum.append(grouping[i] + cur_sum[-1])
            local_max = max(local_max, cur_sum[-1] - binary_search(cur_sum, cur_sum[-1] - m))
            # print(cur_sum, binary_search(cur_sum, cur_sum[-1] - m), local_max)
        ans = max(ans, local_max)

    print(ans)