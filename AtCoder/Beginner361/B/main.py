
def oned_overlap(tlx1, brx1, tlx2, brx2):
    return max(tlx1, tlx2) < min(brx1, brx2)


tlx1, tly1, tlz1, brx1, bry1, brz1 = map(int, input().split())
tlx2, tly2, tlz2, brx2, bry2, brz2 = map(int, input().split())

# check for overlap in x, y, z planes
x_overlap = oned_overlap(tlx1, brx1, tlx2, brx2)
y_overlap = oned_overlap(tly1, bry1, tly2, bry2)
z_overlap = oned_overlap(tlz1, brz1, tlz2, brz2)
if x_overlap and y_overlap and z_overlap:
    print("Yes")
else:
    print("No")

