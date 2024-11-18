
s = list(input())
n = len(s)

st = set()
for i in range(n - 1):
    if s[i] == s[i + 1]:
        st.add(s[i])

if len(st) != 0:
    print(min(list(st)) * 2)
    exit()

for i in range(n - 2):
    if s[i] == s[i + 2]:
        st.add(s[i] + s[i + 1] + s[i + 2])

if len(st) != 0:
    print(min(list(st)))
    exit()
print(-1)