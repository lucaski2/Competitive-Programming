
n = int(input())
nums = list(map(int, input().split()))
s = 0

for i in range(n):
    if i == 0:
        s += abs(nums[i])
    elif i == 1:
        s += abs(-nums[i - 1] * 2 + nums[i])
    else:
        s += abs(nums[i - 2] - 2 * nums[i - 1] + nums[i])

print(s)