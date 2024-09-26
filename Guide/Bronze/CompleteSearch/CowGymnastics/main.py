inp = open("gymnastics.in", "r")
out = open("gymnastics.out", "w")

k, n = list(map(int, inp.readline().strip().split()))



sessions = [list(map(int, inp.readline().strip().split())) for _ in range(k)]

permutations = [(sessions[0][i], sessions[0][j]) for i in range(n) for j in range(n) if i < j]

if k == 1:
    print(len(permutations), file=out)
    exit()


count = 0
for perm in permutations:
    for session in sessions[1:]:
        if session.index(perm[0]) > session.index(perm[1]):
            count += 1
            break

print(len(permutations) - count, file=out)








