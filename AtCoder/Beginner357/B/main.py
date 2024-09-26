a = input()

upper = 0
for i in a:
    if i.isupper():
        upper += 1

print(a.upper() if upper > len(a) // 2 else a.lower())



