
def mad(arr):
    ret = []
    s = set()
    largest = 0
    for i in range(len(arr)):
        if arr[i] in s and arr[i] > largest:
            largest = arr[i]
        s.add(arr[i])
        
        ret.append(largest)
    return ret

# lst = [3, 2, 3, 3, 4, 5, 4, 5, 5, 6]
# for i in range(5):
#     lst = mad(lst)
#     print(lst)



for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = sum(a)
    for i in range(2):
        a = mad(a)
        ans += sum(a)
    # print(a)
    
    a = mad(a)
    if sum(a) == 0:
        print(ans)
        continue

    s = sum(a)

    for i in range(n - 1, min([i for i in range(n) if a[i] != 0]) - 1, -1):
        ans += s
        s -= a[i]

    print(ans)



