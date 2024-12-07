
g1 = [list(input()) for _ in range(3)]
g2 = [list(input()) for _ in range(3)]
green = 0
for i in range(3):
    for j in range(3):
        if g1[i][j] == g2[i][j]:
            green += 1

yellows = -green
s = set([g1[0][0], g1[0][1], g1[0][2], g1[1][0], g1[1][1], g1[1][2], g1[2][0], g1[2][1], g1[2][2]])
cur_g1 = [g1[0][0], g1[0][1], g1[0][2], g1[1][0], g1[1][1], g1[1][2], g1[2][0], g1[2][1], g1[2][2]]
cur_g2 = [g2[0][0], g2[0][1], g2[0][2], g2[1][0], g2[1][1], g2[1][2], g2[2][0], g2[2][1], g2[2][2]]
for c in s:
    yellows += min(cur_g1.count(c), cur_g2.count(c))

print(green)
print(yellows)

