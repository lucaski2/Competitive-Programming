
def transpose(lst):
    new_lst = []
    for i in range(len(lst[0])):
        new_lst.append([])
        for j in range(len(lst)):
            new_lst[i].append(lst[j][i])
    return new_lst

# def unTranspose(lst):
#     new_lst = []
#     for i in range(len(lst)):
#         new_lst.append([])
#         for j in range(len(lst[0])):
#             new_lst[i].append(lst[j][i])
#     return new_lst


def solve(lst, last):
    # rotate lst left
    
    transposed = transpose(lst)
    for i in range(len(transposed)):
        transposed[i] = "".join(transposed[i])

    transposed = sorted(transposed, key=str.lower)


    t = transpose(transposed)
    for i in t:
        for j in i:
            print(j, end="")
        print()
    if not last:
        print()



inp = input()
last = False
while inp != "0 0":
    r, c = list(map(int, inp.split()))

    words = []

    for i in range(r):
        words.append(list(input()))

    inp = input()
    if inp == "0 0":
        last = True
    
    solve(words, last)





