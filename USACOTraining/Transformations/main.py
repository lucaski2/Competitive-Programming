"""
USER: lucaski2
TASK: transform
LANG: PYTHON3
"""

def rotate_90(matrix):
    n = len(matrix)
    return [[matrix[n - j - 1][i] for j in range(n)] for i in range(n)]

def reflect(matrix):
    n = len(matrix)
    return [[matrix[i][n - j - 1] for j in range(n)] for i in range(n)]

inp = open('transform.in', 'r')
out = open('transform.out', 'w')

n = int(inp.readline().strip())
before = [list(inp.readline().strip()) for _ in range(n)]
after = [list(inp.readline().strip()) for _ in range(n)]

if rotate_90(before) == after:
    out.write("1\n")
elif rotate_90(rotate_90(before)) == after:
    out.write("2\n")
elif rotate_90(rotate_90(rotate_90(before))) == after:
    out.write("3\n")
elif reflect(before) == after:
    out.write("4\n")
elif rotate_90(reflect(before)) == after:
    out.write("5\n")
elif rotate_90(rotate_90(reflect(before))) == after:
    out.write("5\n")
elif rotate_90(rotate_90(rotate_90(reflect(before)))) == after:
    out.write("5\n")
elif before == after:
    out.write("6\n")
else:
    out.write("7\n")
