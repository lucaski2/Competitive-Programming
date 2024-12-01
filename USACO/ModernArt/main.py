from copy import deepcopy
from itertools import permutations

def count_possible_first_colors(n, canvas):
    visible_colors = set()
    for i in range(n):
        for j in range(n):
            if canvas[i][j] != 0:
                visible_colors.add(canvas[i][j])

    bounds = {color: [n, 0, n, 0] for color in visible_colors}
    for i in range(n):
        for j in range(n):
            color = canvas[i][j]
            if color != 0:
                bounds[color][0] = min(bounds[color][0], i)  
                bounds[color][1] = max(bounds[color][1], i)  
                bounds[color][2] = min(bounds[color][2], j)  
                bounds[color][3] = max(bounds[color][3], j) 

    ans = 0
    for color in visible_colors:
        perms = permutations(list(visible_colors - {color}))



        for perm in perms:
            
            cur = [[0 for _ in range(n)] for _ in range(n)]
            for i in range(bounds[color][0], bounds[color][1] + 1):
                for j in range(bounds[color][2], bounds[color][3] + 1):
                    cur[i][j] = color
            

            for cur_color in perm:
                for i in range(bounds[cur_color][0], bounds[cur_color][1] + 1):
                    for j in range(bounds[cur_color][2], bounds[cur_color][3] + 1):
                        cur[i][j] = cur_color
            if cur == canvas:
                ans += 1
                break


    return ans

n = int(input())
canvas = [list(map(int, input().strip())) for _ in range(n)]

print(count_possible_first_colors(n, canvas))
