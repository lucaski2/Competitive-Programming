
def binary_insert(arr, target):
    # sorted, reversed array, and find index to insert
    right = len(arr)
    left = 0
    while left < right:
        mid = (left + right) // 2
        if arr[mid] == target:
            left = mid
            break
        elif arr[mid] < target:
            right = mid
        else:
            left = mid + 1
    arr.insert(left, target)



for _ in range(int(input())):
    n, m, k = map(int, input().split())
    starts = list(map(int, input().split()))
    ends = list(map(int, input().split()))
    stations = [[] for _ in range(m)]
    for i in range(n):
        stations[starts[i] - 1].append(ends[i] - 1)
    
    for i in range(m):
        stations[i].reverse()

    num = 0
    ans = 0
    arr = []
    station = 0
    while num < n:
        # pop all in heap that are at station
        while arr and arr[-1] == station:
            arr.pop()
            num += 1
        if num >= n:
            print(ans)
            break
                
        
        cur_station = stations[station]
        for _ in range(k - len(arr)):
            if not cur_station:
                break

            binary_insert(arr, cur_station[-1])
            cur_station.pop()
            
            

        
        station = (station + 1) % m
        ans += 1



