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

	return (min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x)), (
		min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y)
	)

def overlap_area(rect1, rect2, rect3):
  """
  Calculates the area of overlap between three rectangles.

  Args:
      rect1: A dictionary with keys 'x1', 'y1', 'x2', and 'y2' representing the coordinates of the first rectangle.
      rect2: A dictionary with keys 'x1', 'y1', 'x2', and 'y2' representing the coordinates of the second rectangle.
      rect3: A dictionary with keys 'x1', 'y1', 'x2', and 'y2' representing the coordinates of the third rectangle.

  Returns:
      The area of the overlap between the three rectangles.
  """

  # Get the coordinates of each rectangle
  x11, y11, x21, y21 = rect1.values()
  x12, y12, x22, y22 = rect2.values()
  x13, y13, x23, y23 = rect3.values()

  # Find the leftmost and rightmost x-coordinates of the overlap region
  left_x = max(x11, x12, x13)
  right_x = min(x21, x22, x23)

  # Find the topmost and bottommost y-coordinates of the overlap region
  top_y = min(y11, y12, y13)
  bottom_y = max(y21, y22, y23)

  # Calculate the area of the overlap region
  overlap_width = max(0, right_x - left_x)
  overlap_height = max(0, top_y - bottom_y)
  overlap_area = overlap_width * overlap_height

  return overlap_area



white_sheet = list(map(int, input().split()))
blacksheet1 = list(map(int, input().split()))
blacksheet2 = list(map(int, input().split()))

area = (white_sheet[2] - white_sheet[0]) * (white_sheet[3] - white_sheet[1])

if intersect(white_sheet, blacksheet1):
	area -= inter_area(white_sheet, blacksheet1)[0] * inter_area(white_sheet, blacksheet1)[1]
if intersect(white_sheet, blacksheet2):
	area -= inter_area(white_sheet, blacksheet2)[0] * inter_area(white_sheet, blacksheet2)[1]

r1 = {"x1" : blacksheet1[0], "y1" : blacksheet1[1], "x2" : blacksheet1[2], "y2" : blacksheet1[3]}
r2 = {"x1" : blacksheet2[0], "y1" : blacksheet2[1], "x2" : blacksheet2[2], "y2" : blacksheet2[3]}
r3 = {"x1" : white_sheet[0], "y1" : white_sheet[1], "x2" : white_sheet[2], "y2" : white_sheet[3]}

if overlap_area(r1, r2, r3):
	area += overlap_area(r1, r2, r3)

print(area)
if not area <= 0:
	print("YES")
else:
	print("NO")