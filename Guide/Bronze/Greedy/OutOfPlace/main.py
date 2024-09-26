inp = open("outofplace.in", "r")
out = open("outofplace.out", "w")

n = int(inp.readline().strip())

temp_nums = [int(inp.readline().strip()) for _ in range(n)]
nums = []
for i in range(0, n):
    if i != 0 and nums[-1] == temp_nums[i]:
        continue
    nums.append(temp_nums[i])

cnt = 0

for i in range(len(nums) - 1):
    for j in range(len(nums) - 1 - i):
        if nums[j] > nums[j + 1]:
            cnt += 1
            nums[j], nums[j + 1] = nums[j + 1], nums[j]
        
print(cnt, file=out)



