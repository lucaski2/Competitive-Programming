
for _ in range(int(input())):
    s = list(input())
    uppers = []
    lowers = []
    for i in range(len(s)):
        if s[i] == 'b':
            lowers.pop() if lowers else None
            continue
        if s[i] == 'B':
            uppers.pop() if uppers else None
            continue
        if s[i].isupper():
            uppers.append(i)
        else:
            lowers.append(i)
        
    end = ""
    ind1, ind2 = 0, 0

    while ind1 < len(uppers) or ind2 < len(lowers):
        if ind1 < len(uppers) and ind2 >= len(lowers):
            end += s[uppers[ind1]]
            ind1 += 1
            continue
        if ind1 >= len(uppers) and ind2 < len(lowers):
            end += s[lowers[ind2]]
            ind2 += 1
            continue
        if uppers[ind1] < lowers[ind2]:
            end += s[uppers[ind1]]
            ind1 += 1
        else:
            end += s[lowers[ind2]]
            ind2 += 1
    print(end)
