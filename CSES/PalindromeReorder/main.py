
s = list(input())
l = len(s)
ans = [""] * len(s)
sd = {}

for c in s:
    if c not in sd:
        sd[c] = 1
    else:
        sd[c] += 1

odd = 0
for i in sd:
    if sd[i] % 2 == 1:
        ans[len(s) // 2] = i
        odd += 1
if odd > 1:
    print("NO SOLUTION")
    exit()

ind = 0
for s in sd:
    am = sd[s] // 2
    for num in range(am):
        ans[ind + num] = s
        ans[l - 1 - ind - num] = s
    ind += am
print("".join(ans))
