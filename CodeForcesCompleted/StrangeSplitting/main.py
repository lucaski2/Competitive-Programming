import itertools

for _ in range(int(input())):

    n = int(input())
    
    nums = list(map(int, input().split()))

    for i in range(n):
        s = nums[-1] - nums[0]
        if i == 0:
            s = nums[-1] - nums[1]
        
        elif i == n - 1:
            s = nums[-2] - nums[0]
        
        if s != 0:
            print("YES")
            print("R" * (i) + "B" + "R" * (n - i - 1))
            break
    else:
        print("NO")