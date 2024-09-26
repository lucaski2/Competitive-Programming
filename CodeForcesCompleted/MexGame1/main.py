
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    nums = {}
    for i in range(n):
        if a[i] in nums:
            nums[a[i]] += 1
        else:
            nums[a[i]] = 1
    
    nums = list(nums.items())
    last = -1
    only_one_used = False
    for num in nums:
        if num[0] != last + 1:
            print(last + 1)
            break
        if num[1] == 1:
            if only_one_used:
                print(last + 1)
                break
            else:
                only_one_used = True
        last = num[0]
    else:
        print(last + 1)



