import itertools as it

inp = open("lineup.in", "r")
out = open("lineup.out", "w")
n = int(inp.readline().strip())
constraints = [inp.readline().strip().split() for _ in range(n)]

perms = it.permutations(["Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"])
for perm in perms:
    all_satisfied = True
    for c in constraints:
        ind = perm.index(c[0])
        constraint_satisfied = False
        if ind > 0 and perm[ind- 1] == c[-1]:
            constraint_satisfied = True
        elif ind < len(perm) - 1 and perm[ind + 1] == c[-1]:
            constraint_satisfied = True
        if not constraint_satisfied:
            all_satisfied = False
    if all_satisfied:
        for p in perm:
            out.write(p + "\n")
        break
    


