import itertools

n = int(input())

petals = list(map(int, input().split()))

combos = list(itertools.combinations(range(n), 2))


cnt = n

for combo in combos:
    avg = sum(petals[combo[0]:combo[1] + 1]) / (combo[1] - combo[0] + 1) 
    if avg in petals[combo[0]:combo[1] + 1]:
        cnt += 1

print(cnt)

