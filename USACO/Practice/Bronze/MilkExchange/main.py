N, M = list(map(int, input().split()))

order = input()

original_capacities = list(map(int, input().split()))
capacities = [0 for _ in range(N)]

for j in range(N):


    if order[j] == "R":
        capacities[(j + M) % N] += M if original_capacities[j] > M else original_capacities[j]
    if order[j] == "L":
        capacities[(j - M) % N] += M if original_capacities[j] > M else original_capacities[j]
print(capacities)
total = 0
for i in range(N):
    if capacities[i] > original_capacities[i]:
        total += original_capacities[i]
    else:
        total += capacities[i]

print(total)