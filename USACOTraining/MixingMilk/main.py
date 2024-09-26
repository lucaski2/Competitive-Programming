"""
USER: lucaski2
TASK: milk
LANG: PYTHON3
"""

inp = open('milk.in', 'r')
out = open('milk.out', 'w')
n, m = map(int, inp.readline().split())
farmers = [list(map(int, inp.readline().split())) for _ in range(m)]
farmers.sort(key=lambda x: x[0])

cost = 0

for i in range(m):
    cost += min(n, farmers[i][1]) * farmers[i][0]
    n -= min(n, farmers[i][1])

out.write(str(cost) + '\n')


