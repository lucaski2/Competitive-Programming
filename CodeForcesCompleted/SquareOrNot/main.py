from math import sqrt
for _ in range(int(input())):
    n = int(input())
    s = list(map(int, list(input())))
    if not sqrt(n).is_integer():
        print('NO')
        continue

    mat = [[0] * int(sqrt(n)) for _ in range(int(sqrt(n)))]
    for i in range(int(sqrt(n))):
        for j in range(int(sqrt(n))):
            mat[i][j] = s[i * int(sqrt(n)) + j]
    # check valid, 
    valid = True
    for i in range(int(sqrt(n))):
        for j in range(int(sqrt(n))):
            if i == 0 or j == 0 or i == int(sqrt(n)) - 1 or j == int(sqrt(n)) - 1:
                if mat[i][j] == 0:
                    valid = False
            else:
                if mat[i][j] == 1:
                    valid = False
    print('YES' if valid else 'NO')