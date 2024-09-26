for _ in range(int(input())):
    inp = int(input())
    lst = []
    for ind, i in enumerate(str(inp)):
        if i == '0':
            continue
        lst.append(i + str((10 ** (len(str(inp)) - ind - 1)))[1:])
    

    print(len(lst))
    print(*lst)

