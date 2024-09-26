import sys
N = int(input())
ints = list(map(int, input().split()))

prev = ints[-1]
start_ind = -1
out = ""
seq = False
for i in range(N - 2, -1, -1):

    if seq and ints[i] <= prev:
        out = f"{i + 1} {start_ind + 1}"
        seq = False

    if ints[i] > prev and not seq:
        seq = True
        start_ind = i + 1
        if out != "":
            print("impossible")
            sys.exit()



    prev = ints[i]

if out != "":
    print(out)
else:
    print(str(len(ints) - 1) + " " + str(len(ints) - 1))







