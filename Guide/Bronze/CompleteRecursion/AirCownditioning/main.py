import itertools as it

n, m = list(map(int, input().split()))

requirements = [list(map(int, input().split())) for _ in range(n)]

conditioner_info = [list(map(int, input().split())) for _ in range(m)]

temp_needed = [0 for _ in range(100)]

for i in range(len(requirements)):
    for j in range(requirements[i][0] - 1, requirements[i][1]):
        if temp_needed[j] < requirements[i][2]:
            temp_needed[j] = requirements[i][2]


perms = set(it.combinations([0, 1] * m, m))
lowest_cost = 10**7
for val in perms:
    cur_temp_needed = temp_needed.copy()
    cost = 0
    for ind, on in enumerate(val):
        if on == 0:
            continue
        cost += conditioner_info[ind][3]
        for i in range(conditioner_info[ind][0] - 1, conditioner_info[ind][1]):
            cur_temp_needed[i] -= conditioner_info[ind][2]
    if max(cur_temp_needed) <= 0:
        lowest_cost = min(lowest_cost, cost)
        
print(lowest_cost)

