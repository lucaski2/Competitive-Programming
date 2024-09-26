nums_len = int(input())

nums = [int(x) for x in input().split()]
current_num = nums[0]
end_nums = [nums[0]]

for num in nums:
    if current_num < num:
        current_num = num
        end_nums.append(num)

print(len(end_nums))

for num in end_nums:
    print(num, end=" ")
print()