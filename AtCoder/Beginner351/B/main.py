n = int(input())
g1 = [list(input()) for _ in range(n)]
g2 = [list(input()) for _ in range(n)]
for i in range(n):
    for j in range(n):
        if g1[i][j] != g2[i][j]:
            print(i + 1, j + 1)
            exit()


