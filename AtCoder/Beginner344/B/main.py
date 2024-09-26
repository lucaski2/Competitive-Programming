
inp = []
cur = input()
while cur != '0':
    inp.append(cur)
    cur = input()
inp.append('0')
for i in reversed(inp):
    print(i)



