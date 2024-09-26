inp = open("breedflip.in", 'r')
out = open("breedflip.out", 'w')

n = int(inp.readline())

a = inp.readline().strip()
b = inp.readline().strip()

to_be_reversed = []

for i in range(n):
    if a[i] != b[i]:
        to_be_reversed.append(i)

cnt = 0
last = -1
for i in range(len(to_be_reversed)):
    if last == -1:
        cnt += 1
    
    elif to_be_reversed[i] != last + 1:
        cnt += 1

    last = to_be_reversed[i]

print(cnt, file=out)


