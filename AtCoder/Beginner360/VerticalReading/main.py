
s, t = input().split()
for i in range(len(s)):
    for j in range(i):
        cur_str = ""
        for k in range(0, len(s), i):
            try:
                cur_str += s[k + j]
            except:
                pass
        if cur_str == t:
            print("Yes")
            exit()
print("No")