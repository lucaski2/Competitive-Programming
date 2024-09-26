
parens = input()

lst = []

b = 0

for ind, paren in enumerate(parens):
    lst.append((b, ind))
    if paren == "(":
        b += 1
    
    else:
        b -= 1

lst.sort(key=lambda x: x[0], reverse=True)
lst = list(reversed(lst))

for i in range(len(lst)):
    print(parens[lst[i][1]], end="")
print()

