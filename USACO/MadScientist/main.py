inp = open('breedflip.in', 'r')
out = open('breedflip.out', 'w')
n = int(inp.readline())


s1 = inp.readline()
s2 = inp.readline()
cur = False
ans = 0
for i in range(n):
    if s1[i] != s2[i]:
        cur = True
    elif cur:
        ans += 1
        cur = False
if cur:
    ans += 1
print(ans, file=out)