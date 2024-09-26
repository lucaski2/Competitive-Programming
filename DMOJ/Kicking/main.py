
def binary_search1(arr, target, start):
    l = 0
    r = len(arr) - 1
    while l <= r:
        mid = (l + r) // 2
        if arr[mid] < start:
            l = mid + 1
        elif arr[mid] > start + target:
            r = mid - 1
        else:
            return True
    return False

def binary_search2(arr, target, start):
    l = 0
    r = len(arr) - 1
    while l <= r:
        mid = (l + r) // 2
        if arr[mid] > start:
            r = mid - 1
        elif arr[mid] < start - target:
            l = mid + 1
        else:
            return True
    return False

n, m, k = map(int, input().split())
grid = [list(input()) for _ in range(n)]
grida = [[] for _ in range(n)]
gridb = [[] for _ in range(n)]

for i in range(n):
    for j in range(m):
        if grid[i][j] == 'A':
            grida[i].append(j)
        elif grid[i][j] == 'B':
            gridb[i].append(j)

grid_end = [['.'] * m for _ in range(n)]

for i in range(n):
    for j in range(m):
        if grid[i][j] == 'A':
            ans = binary_search1(gridb[i], k, j)
            if ans == False:
                grid_end[i][j] = 'Y'
            else:
                grid_end[i][j] = 'N'
        elif grid[i][j] == 'B':
            ans = binary_search2(grida[i], k, j)
            if ans == False:
                grid_end[i][j] = 'Y'
            else:
                grid_end[i][j] = 'N'


for i in range(n):
    print(''.join(grid_end[i]))