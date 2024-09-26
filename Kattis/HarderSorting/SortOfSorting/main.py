


def insert(lst, inp):
    for i in range(len(lst)):
        if inp[:2] < lst[i][:2]:
            lst.insert(i, inp)
            return lst
    
    lst.append(inp)
    return lst






inp = int(input())


while inp != 0:
    lst = []
    for i in range(inp):
        lst = insert(lst, input())

    
    for i in lst:
        print(i)
    
    inp = int(input())

    if inp != 0:
        print()



