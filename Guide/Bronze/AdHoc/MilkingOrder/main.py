inp = open("milkorder.in", "r")
out = open("milkorder.out", "w")

n, m, k = list(map(int, inp.readline().strip().split()))
heirarchy = list(map(int, inp.readline().strip().split()))
left_and_specified = heirarchy.copy()

spef_order = [-1 for _ in range(n)]

for i in range(k):
    cur = list(map(int, inp.readline().strip().split()))
    if cur[0] in left_and_specified:
        left_and_specified.remove(cur[0])
    spef_order[cur[1] - 1] = cur[0]

basis = False
for i in heirarchy:
    if i in spef_order:
        basis = True
        break

if basis:

    ref = 0
    for i in range(len(heirarchy)):
        if heirarchy[i] in spef_order:
            ref = i
            break


    while len(left_and_specified) > 0:
        cur = left_and_specified.pop()
        if heirarchy.index(cur) < ref:
            for i in range(spef_order.index(heirarchy[ref]) - 1, -1, -1):
                if spef_order[i] == -1:
                    spef_order[i] = cur
                    break
        else:
            for i in range(len(spef_order) - 1, -1, -1):
                if spef_order[i] == -1:
                    spef_order[i] = cur
                    break
    for i in range(len(spef_order)):
        if spef_order[i] == -1:
            print(i + 1, file=out)
            break
            

else:
    for i in range(len(spef_order)):
        if spef_order[i] == -1:
            print(i, file=out)
            break







