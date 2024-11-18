n = int(input())
s = input()
if n > len(s):
    print("NO")
    exit()
cur = set()
asdf = ""
ans = []
for i in range(len(s)):
    if n > 0 and s[i] not in cur:
        cur.add(s[i])
        n -= 1
        if i != 0:
            ans.append(asdf)
            asdf = ""
            
    asdf += s[i]

if n == 0:
    ans.append(asdf)
    print("YES")
    print("\n".join(ans))
else:
    print("NO")
