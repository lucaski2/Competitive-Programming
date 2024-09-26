inp = open("cownomics.in", "r")
out = open("cownomics.out", "w")

n, m = map(int, inp.readline().strip().split())

genomes = [inp.readline().strip() for _ in range(n * 2)]

perms = [(i, j, k) for i in range(m - 2) for j in range(m - 1) for k in range(m) if i < j < k]

count = 0

for perm in perms:
    spotty_perms = set()
    for i in range(n):
        # base 4
        num = 0
        for j in range(3):
            if genomes[i][perm[j]] == "A":
                num += 0 * (3 - j)
            elif genomes[i][perm[j]] == "C":
                num += 1 * (3 - j)
            elif genomes[i][perm[j]] == "G":
                num += 2 * (3 - j)
            
            else:
                num += 3 * (3 - j)
        spotty_perms.add(num)
        print(num, genomes[i][perm[0]] + genomes[i][perm[1]] + genomes[i][perm[2]], perm)

    print()            
    
    for i in range(n, n * 2):
        num = 0
        for j in range(3):
            if genomes[i][perm[j]] == "A":
                num += 0 * (3 - j)
            elif genomes[i][perm[j]] == "C":
                num += 1 * (3 - j)
            elif genomes[i][perm[j]] == "G":
                num += 2 * (3 - j)
            
            else:
                num += 3 * (3 - j)
        if num in spotty_perms:
            break
        print(num, genomes[i][perm[0]] + genomes[i][perm[1]] + genomes[i][perm[2]], perm)

    else:
        count += 1
    

print(count, file=out)

