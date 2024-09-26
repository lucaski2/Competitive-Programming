

n = int(input())
giants = [list(map(int, input().split())) for _ in range(n)]
largest = max(giants, key=lambda x: x[1] - x[0])
s = 0
for g in giants:
    s += g[0]


print(largest[1] - largest[0] + s)
