s = []

while True:
    try:
        s.append(input())
    
    except EOFError:
        break


lst = []

current_lst = []
for i in range(len(s)):
    if s[i] == "":
        lst.append(current_lst)
        current_lst = []
    else:
        current_lst.append(list(reversed(s[i])))
    if i == len(s) - 1:
        lst.append(current_lst)


# for part in lst:
#     # sort
#     for i in range(len(part)):
#         for j in range(len(part) - 1 - i):
#             if part[j] > part[j + 1]:
                

for i in range(len(lst)):
    lst[i] = ["".join(k) for k in lst[i]]
    lst[i] = sorted(lst[i])
    greatest = max(lst[i], key=len)
    for j in range(len(lst[i])):
        print(" " * (len(greatest) - len(lst[i][j])) + lst[i][j][::-1])
    
    if i != len(lst) - 1:
        print()

