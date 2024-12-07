
for _ in range(int(input())):
    things = set()
    n = int(input())
    nums = list(map(int, input().split()))

    for i in range(n - 2):
        s = nums[i:i+3]
        for j in range(3):
            if s.count(s[j]) >= 2:
                things.add(s[j])
    
    things = list(things)
    things.sort()

    if n == 2:
        if nums[0] == nums[1]:
            print(nums[0])
        else:
            print(-1)
        continue

    if len(things) == 0:
        print(-1)
    else:
        print(*things)

