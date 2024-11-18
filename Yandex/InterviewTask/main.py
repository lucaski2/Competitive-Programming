

# testing
amount = 1000
cur = [1, 1]
for i in range(7):
    print(cur.count(i + 1))
    new = []
    for j in range(len(cur) - 1):
        new.append(cur[j])
        new.append(cur[j] + cur[j + 1])
    new.append(cur[-1])
    cur = new

print(cur.count(7))





