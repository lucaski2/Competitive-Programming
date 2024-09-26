lst = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ{}")
lst2 = list("JICOSDHG{QNFUVWLEZYXPTKMR}AB")
text = list("RKPUYPFCIAKKJMYZZJT")
print(lst, lst2, text)
for i in range(len(lst2)):
    l = lst.pop()
    lst.insert(0, l)
    for i in text:
        print(lst[lst2.index(i)], end="")
    print()