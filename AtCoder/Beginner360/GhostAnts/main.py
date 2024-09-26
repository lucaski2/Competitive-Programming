n, t = map(int, input().split())
directions = list(map(int, list(input())))
coordinates = list(map(int, input().split()))

zeros = []
ones = []

for i in range(n):
    if directions[i] == 0:
        zeros.append(coordinates[i])
    else:
        ones.append(coordinates[i])

zeros.sort()
ones.sort()



def get_number(opposites: list[int], point) -> int:
    left = 0
    right = len(opposites) - 1
    while left <= right:
        middle = (left + right) // 2
        if opposites[middle] >= point:
            if middle == 0 or opposites[middle - 1] < point:
                return middle
            else:
                right = middle - 1
        
        elif opposites[middle] < point:
            left = middle + 1
        
    return -1


def get_number2(opposites: list[int], point) -> int:
    left = 0
    right = len(opposites) - 1
    while left <= right:
        middle = (left + right) // 2
        if opposites[middle] <= point:
            if middle == len(opposites) - 1 or opposites[middle + 1] > point:
                return middle
            else:
                left = middle + 1
        
        elif opposites[middle] > point:
            right = middle - 1
        
    return -1





# print(zeros)
# print(ones)

s = 0
for i in range(len(zeros)):
    get1 = get_number(ones, zeros[i] - 2 * t)
    get2 = get_number2(ones, zeros[i])
    if get1 == -1 or get2 == -1:
        continue
    s += (get2 - get1 + 1)
    

print(s)