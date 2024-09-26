
for _ in range(int(input())):
    s = list(input())
    t = list(input())
    ind = 0
    for i in range(len(s)):
        if ind == len(t):
            if s[i] == "?":
                s[i] = 'a'
            continue
        

        elif s[i] == t[ind] or s[i] == "?":
            s[i] = t[ind]
            ind += 1
        

    if ind == len(t):
        print("YES")
        print("".join(s))
    else:
        print("NO")