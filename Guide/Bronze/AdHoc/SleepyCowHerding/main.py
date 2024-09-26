inp = open("herding.in", "r")
out = open("herding.out", "w")

pos = map(int, inp.readline().split())
pos = sorted(pos)

gaps = []
for i in range(len(pos) - 1):
    gaps.append(pos[i+1] - pos[i] - 1)
    if gaps[-1] == 0:
        gaps.pop()


if 1 in gaps:
    print(1, file=out)
elif len(gaps) == 0:
    print(0, file=out)

else:
    print(2, file=out)

if len(gaps) == 0:
    print(0, file=out)
else:
    print(max(gaps), file=out)


