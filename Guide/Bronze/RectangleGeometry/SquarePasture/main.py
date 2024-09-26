inp = open("square.in", "r")
out = open("square.out", "w")

s1 = list(map(int, inp.readline().split()))
s2 = list(map(int, inp.readline().split()))

length = max(s1[3], s2[3]) - min(s1[1], s2[1])
height = max(s1[2], s2[2]) - min(s1[0], s2[0])
print(max(height, length) ** 2, file=out)

