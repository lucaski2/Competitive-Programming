
s = list(input())
t = list(input().lower())
if t[-1] == "x":
    t.pop()

cur_ind = 0

for i in range(len(s)):
    if s[i] == t[cur_ind]:
        cur_ind += 1
    
    if cur_ind == len(t):
        break

print("Yes" if cur_ind == len(t) else "No")


