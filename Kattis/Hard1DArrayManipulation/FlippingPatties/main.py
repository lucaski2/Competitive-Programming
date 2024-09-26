from math import ceil
N = int(input())

instructions = []
for i in range(N):
    instructions.append(list(map(int, input().split())))

times_action_needed = []


for i in range(N):
    times_action_needed.append(instructions[i][1] - (instructions[i][0] * 2))
    times_action_needed.append(instructions[i][1])
    times_action_needed.append(instructions[i][1] - (instructions[i][0]))



times_action_needed.sort()
largest = 0

for i in set(times_action_needed):
    if times_action_needed.count(i) > largest:
        largest = times_action_needed.count(i)

print(ceil(largest/2))

