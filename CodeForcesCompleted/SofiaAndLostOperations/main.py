
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    m = int(input())
    d = list(map(int, input().split()))
    nums = {}
    for i in range(m):
        if d[i] in nums:
            nums[d[i]] += 1
        else:
            nums[d[i]] = 1
    
    for i in range(n):
        if a[i] == b[i]:
            continue
        if b[i] in nums:
            nums[b[i]] -= 1
            if nums[b[i]] == 0:
                del nums[b[i]]
        else:
            print("NO")
            break
    else:
        if d[-1] not in b:
            print("NO")
            continue
        print("YES")
