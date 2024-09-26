num_len = int(input())
nums = list(map(int, input().split(' ')))

num_pivot = 0
highest = [0 for _ in range(num_len)]
lowest = [0 for _ in range(num_len)]
current_lowest = nums[-1]
current_highest = nums[0]
# go through list backwards and get the lowest at any given index
for i in range(num_len - 2, 0, -1):
    if nums[i] < current_lowest:
        current_lowest = nums[i]
    lowest[i] = current_lowest

for i in range(1, num_len - 1):
    if nums[i] > current_highest:
        current_highest = nums[i]
    highest[i] = current_highest

for i in range(1, num_len - 1):
    if highest[i] == lowest[i]:
        num_pivot += 1





if nums[-1] >= max(nums[:-1]):
    num_pivot += 1

if nums[0] < min(nums[1:]):
    num_pivot += 1
        
print(num_pivot)

