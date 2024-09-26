s = sum(list(map(int, input().split())))
lst = list(range(0, 10))
lst.remove(s)
print(lst[0])