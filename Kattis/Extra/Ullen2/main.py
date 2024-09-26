length = int(input())
inp = []
for i in range(length):
    inp.append(input())

while len(inp) != 0:
    if len(inp) > 13:
        print(inp[12])
        inp.pop(12)

    else:
        print(inp[13 % len(inp) - 1])
        inp.pop(13 % len(inp) - 1)
