inp = open("billboard.in", "r")
out = open("billboard.out", "w")

lawn_bill = list(map(int, inp.readline().strip().split()))
feed_bill = list(map(int, inp.readline().strip().split()))

def intersect(s1, s2) -> bool:
	bl_a_x, bl_a_y, tr_a_x, tr_a_y = s1[0], s1[1], s1[2], s1[3]
	bl_b_x, bl_b_y, tr_b_x, tr_b_y = s2[0], s2[1], s2[2], s2[3]

	# no overlap
	if bl_a_x >= tr_b_x or tr_a_x <= bl_b_x or bl_a_y >= tr_b_y or tr_a_y <= bl_b_y:
		return False
	else:
		return True


def inter_area(s1, s2) -> int:
	bl_a_x, bl_a_y, tr_a_x, tr_a_y = s1[0], s1[1], s1[2], s1[3]
	bl_b_x, bl_b_y, tr_b_x, tr_b_y = s2[0], s2[1], s2[2], s2[3]

	return max(0, ((min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x)))), max(0, (
		min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y)
	))

lawn_width, lawn_length = lawn_bill[2] - lawn_bill[0], lawn_bill[3] - lawn_bill[1]

is_intersecting = intersect(lawn_bill, feed_bill)
if is_intersecting:
    intersection = inter_area(lawn_bill, feed_bill)

    if (intersection[0] == lawn_width and intersection[1] == lawn_length) or intersection[0] == lawn_width or intersection[1] == lawn_length:
        print((lawn_bill[2] - lawn_bill[0]) * (lawn_bill[3] - lawn_bill[1]) - intersection[0] * intersection[1], file=out)
        exit()
print((lawn_bill[2] - lawn_bill[0]) * (lawn_bill[3] - lawn_bill[1]), file=out)
