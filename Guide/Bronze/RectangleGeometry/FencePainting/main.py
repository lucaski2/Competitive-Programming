inp = open("paint.in", "r")
out = open("paint.out", "w")

paint1 = list(map(int, inp.readline().split()))
paint2 = list(map(int, inp.readline().split()))


# get overlap
def overlapping(p1, p2) -> bool:
    return max(p1[0], p2[0]) <= min(p1[1], p2[1])

if overlapping(paint1, paint2):
    print(str(max(paint1[1], paint2[1]) - min(paint1[0], paint2[0])), file=out)
else:
    print(paint1[1] - paint1[0] + paint2[1] - paint2[0], file=out)

