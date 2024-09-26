
n = int(input())

beans = {}

for i in range(n):
    inp = list(map(int, input().split()))
    if inp[1] in beans:
        beans[inp[1]] = min(beans[inp[1]], inp[0])
    
    else:
        beans[inp[1]] = inp[0]

m = 0
for i in beans.values():
    m = max(m, i)

print(m)

