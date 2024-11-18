filein = "input.txt"
fileout = "output.txt"

inp = open(filein, "r")
out = open(fileout, "w")

n, k = map(int, inp.readline().split())
honey_jars = list(map(int, inp.readline().split()))
amount_piglet_eats = 0
for i in range(n):
    amount_piglet_eats += honey_jars[i] - min(k * 3, honey_jars[i] // k * k)

print(amount_piglet_eats, file=out)