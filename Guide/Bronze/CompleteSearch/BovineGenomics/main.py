inp = open("cownomics.in", "r")
out = open("cownomics.out", "w")
n, m = map(int, inp.readline().strip().split())
genes = [inp.readline().strip() for _ in range(n * 2)]
count = 0
for i in range(m):
    spots = ""
    for j in range(n):
        spots += genes[j][i]
    
    for j in range(n, n * 2):
        if genes[j][i] in spots:
            break
    else:
        count += 1

print(count, file=out)
