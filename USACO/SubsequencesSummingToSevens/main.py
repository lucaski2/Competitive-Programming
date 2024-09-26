inp = open("div7.in", 'r')
out = open("div7.out", 'w')

n = int(inp.readline().strip())
a = [int(inp.readline()) for _ in range(n)]

p_sum = [0]

for i in range(n):
    p_sum.append((p_sum[-1] + a[i]) % 7)

ans = 0
first_instance = {}
for i in range(n + 1):
    if p_sum[i] not in first_instance:
        first_instance[p_sum[i]] = i
    else:
        ans = max(ans, i - first_instance[p_sum[i]])
print(ans, file=out)














