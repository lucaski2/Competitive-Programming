inp = open("billboard.in", "r")
out = open("billboard.out", "w")

b1 = list(map(int, inp.readline().strip().split()))
b2 = list(map(int, inp.readline().strip().split()))
truck = list(map(int, inp.readline().strip().split()))

def intersect(a1, b2):
    
    if a1[3] <= b2[1] or a1[1] >= b2[3]:
        return False
    if a1[2] <= b2[0] or a1[0] >= b2[2]:
        return False
    
    bl_a_x, bl_a_y, tr_a_x, tr_a_y = a1[0], a1[1], a1[2], a1[3]
    bl_b_x, bl_b_y, tr_b_x, tr_b_y = b2[0], b2[1], b2[2], b2[3]

    return (min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x)) * (
        min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y)
    )

intersection1 = intersect(truck, b2)
intersection2 = intersect(b1, truck)
area1 = (b1[2] - b1[0]) * (b1[3] - b1[1])
area2 = (b2[2] - b2[0]) * (b2[3] - b2[1])


if intersection1 == False and intersection2 == False:
    print(area1 + area2, file=out)

elif intersection2 == False:
    print(area1 + area2 - intersection1, file=out)

elif intersection1 == False:
    print(area1 + area2 - intersection2, file=out)
else:
    print(area1 + area2 - intersection1 - intersection2, file=out)











