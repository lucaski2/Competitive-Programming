import math

p1 = list(map(int, input().split()))
p2 = list(map(int, input().split()))
p3 = list(map(int, input().split()))
coordinates = [p1, p2, p3]
if coordinates.count(coordinates[0]) == len(coordinates):
    print("No")
    exit()
# go through coordinates and check if that coordinate is the right triangle angle

for i in range(len(coordinates)):
    try:
        other_coords = coordinates.copy()
        other_coords.pop(i)
        try:
            slope1 = (other_coords[0][1] - coordinates[i][1]) / (other_coords[0][0] - coordinates[i][0])
        except:
            slope1 = None
        try:
            slope2 = (other_coords[1][1] - coordinates[i][1]) / (other_coords[1][0] - coordinates[i][0])
        except:
            slope2 = None

        if None in [slope1, slope2] and 0 in [slope1, slope2]:
            print("Yes")
            break
        elif None in [slope1, slope2]:
            continue
        if math.isclose(slope1 ** -1, -slope2):
            print("Yes")
            break
        if math.isclose(slope2 ** -1, -slope1):
            print("Yes")
            break
    except:
        pass


else:
    print("No")




