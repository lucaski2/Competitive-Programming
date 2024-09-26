from itertools import permutations

n = int(input())
cows = ['Bessie', 'Buttercup', 'Belinda', 'Beatrice', 'Bella', 'Blue', 'Betsy', 'Sue']
constraints = []
for _ in range(n):
    a, _, _, _, _, b = input().split()
    constraints.append((a, b))

things = []
for perm in permutations(cows):
    for a, b in constraints:
        if abs(perm.index(a) - perm.index(b)) != 1:
            break
    else:
        things.append(" ".join(perm))
things.sort()
print(*things[0].split(), sep="\n")

