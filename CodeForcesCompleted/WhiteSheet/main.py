
def amount_overlap_2(rect1, rect2):

    # Find the coordinates of the overlapping rectangle
    x_left = max(rect1[0], rect2[0])
    y_bottom = max(rect1[1], rect2[1])
    x_right = min(rect1[2], rect2[2])
    y_top = min(rect1[3], rect2[3])

    # Check if there is an overlap
    if x_right > x_left and y_top > y_bottom:
        return (x_right - x_left) * (y_top - y_bottom)
    else:
        return 0

def amount_overlap_3(rect1, rect2, rect3):

    # Find the coordinates of the overlapping rectangle
    x_left = max(rect1[0], rect2[0], rect3[0])
    y_bottom = max(rect1[1], rect2[1], rect3[1])
    x_right = min(rect1[2], rect2[2], rect3[2])
    y_top = min(rect1[3], rect2[3], rect3[3])

    # Check if there is an overlap
    if x_right > x_left and y_top > y_bottom:
        return (x_right - x_left) * (y_top - y_bottom)
    else:
        return 0

r1 = list(map(int, input().split()))
r2 = list(map(int, input().split()))
r3 = list(map(int, input().split()))

r1_area = (r1[3] - r1[1]) * (r1[2] - r1[0])
# print(r1_area)
# print(amount_overlap_2(r1, r2))
# print(amount_overlap_2(r1, r3))
# print(amount_overlap_3(r1, r2, r3))
if r1_area - amount_overlap_2(r1, r2) - amount_overlap_2(r1, r3) + amount_overlap_3(r1, r2, r3) == 0:
    print("NO")
else:
    print("YES")