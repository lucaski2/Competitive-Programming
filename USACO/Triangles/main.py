
n = int(input())
points = [list(map(int, input().split())) for _ in range(n)]

ans = 0

for i in range(n):
  for j in range(i, n):
    for k in range(j, n):
      if points[i][0] == points[j][0] or points[i][0] == points[k][0] or points[j][0] == points[k][0]:
        if points[j][1] == points[k][1] or points[j][1] == points[i][1] or points[k][1] == points[i][1]:
          # area of rectangle formed by right angle triangle with sides parallel to x and y axis
          # find which pair is the vertical side
          vertical = (i, j) if points[i][0] == points[j][0] else (j, k) if points[j][0] == points[k][0] else (i, k)
          horizontal = (i, j) if points[i][0] != points[j][0] else (j, k) if points[j][0] != points[k][0] else (i, k)
          ans = max(ans, abs(points[vertical[0]][1] - points[vertical[1]][1]) * abs(points[horizontal[0]][0] - points[horizontal[1]][0]))

print(int(ans), end='\n')

