import math
n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]

for i in range(n):
    largest_distance = 0
    largest_index = -1
    for j in range(n):
        if i == j:
            continue

        if math.sqrt((points[i][0] - points[j][0])**2 + (points[i][1] - points[j][1])**2) > largest_distance:
            largest_distance = math.sqrt((points[i][0] - points[j][0])**2 + (points[i][1] - points[j][1])**2)
            largest_index = j
    
    print(largest_index + 1)



