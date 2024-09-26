import itertools, math

inp = open("triangles.in", 'r')
out = open("triangles.out", 'w')

N = int(inp.readline())

posts = [list(map(int, inp.readline().strip().split())) for _ in range(N)]




largest = 0

for i in range(N):
    for j in range(N):
        for k in range(N):
            if i != j and j != k and i != k:
                # check triangle
                if posts[i][1] == posts[j][1] and posts[i][0] == posts[k][0]:
                    area = abs((posts[j][0] - posts[i][0]) * (posts[k][1] - posts[i][1])) / 2
                    if area > largest:
                        largest = area
print(int(largest * 2), file=out)



