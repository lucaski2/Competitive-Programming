def solve(s, str, n):
    sep = s.split(str, n)
    if len(sep) <= n:
        return -1
    return len(s) - len(sep[-1]) - len(str)


inp = open("circlecross.in", "r")
out = open("circlecross.out", "w")

letters = inp.readline().strip()

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
perms = [((solve(letters, alphabet[i], 1), solve(letters, alphabet[i], 2)), (solve(letters, alphabet[j], 1), solve(letters, alphabet[j], 2))) for i in range(26) for j in range(26) if i > j]

count = 0

for perm in perms:

    if perm[0][0] < perm[1][0] < perm[0][1] < perm[1][1] or perm[1][0] < perm[0][0] < perm[1][1] < perm[0][1]:
        count += 1

print(count, file=out)

