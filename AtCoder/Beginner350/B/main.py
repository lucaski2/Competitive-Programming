
n, q = list(map(int, input().split()))

s = {}
inp = list(map(int, input().split()))

for i in range(len(inp)):
    s[inp[i]] = 1 if inp[i] not in s else s[inp[i]] + 1
    

am = n
for i in s.values():
    am -= 1 if i % 2 == 1 else 0

print(am)


