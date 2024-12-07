n, q = map(int, input().split())

line = input().split()

for i in range(0, n, 2):
    line[i] = list(line[i])
    line[i][0] = line[i][0].upper()
    line[i] = "".join(line[i])




for i in range(q):
    l, r, statement = input().split()
    statement = list(statement)
    statement[0] = statement[0].upper()
    statement = "".join(statement)
    l = int(l)
    r = int(r)

    e = eval(" ".join(line[:l-1] + [str(True)] + line[r:]))
    e2 = eval(" ".join(line[:l-1] + [str(False)] + line[r:]))

    # print(e, e2)


    if e == eval(statement) or e2 == eval(statement):
        print("Y", end="")
    else:
        print("N", end="")






print()

