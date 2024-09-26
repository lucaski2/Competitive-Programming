inp = open("swap.in", "r")
out = open("swap.out", "w")

n, k = map(int, inp.readline().split())

switch1 = list(map(int, inp.readline().split()))
switch2 = list(map(int, inp.readline().split()))
switch1 = [x - 1 for x in switch1]
switch2 = [x - 1 for x in switch2]


cows = [i for i in range(1, n + 1)]

starting = [i for i in range(1, n + 1)]


# check for overlap between switch1 range and switch2  range
overlap_start = max(switch1[0], switch2[0])
overlap_end = min(switch1[1], switch2[1])
if overlap_start <= overlap_end:
    overlap = True
else:
    overlap = False

if not overlap:
    
    if k % 2 != 0:
        if switch1[1] == len(cows) - 1:
            cows = cows[:switch1[0]] + list(reversed(cows[switch1[0]:switch1[1] + 1]))
        else:   
            cows = cows[:switch1[0]] + list(reversed(cows[switch1[0]:switch1[1] + 1])) + cows[switch1[1] + 1:]
        if switch2[1] == len(cows) - 1:
            cows = cows[:switch2[0]] + list(reversed(cows[switch2[0]:switch2[1] + 1]))
        else:
            cows = cows[:switch2[0]] + list(reversed(cows[switch2[0]:switch2[1] + 1])) + cows[switch2[1] + 1:]

    for i in range(n):
        print(cows[i], file=out)


else:
    cnt = 0
    while cows != starting or cnt == 0:

        if switch1[1] == len(cows) - 1:
            cows = cows[:switch1[0]] + list(reversed(cows[switch1[0]:switch1[1] + 1]))
        else:   
            cows = cows[:switch1[0]] + list(reversed(cows[switch1[0]:switch1[1] + 1])) + cows[switch1[1] + 1:]
        if switch2[1] == len(cows) - 1:
            cows = cows[:switch2[0]] + list(reversed(cows[switch2[0]:switch2[1] + 1]))
        else:
            cows = cows[:switch2[0]] + list(reversed(cows[switch2[0]:switch2[1] + 1])) + cows[switch2[1] + 1:]
        cnt += 1
    
    for _ in range(k % cnt):
        if switch1[1] == len(cows) - 1:
            cows = cows[:switch1[0]] + list(reversed(cows[switch1[0]:switch1[1] + 1]))
        else:
            cows = cows[:switch1[0]] + list(reversed(cows[switch1[0]:switch1[1] + 1])) + cows[switch1[1] + 1:]
        if switch2[1] == len(cows) - 1:
            cows = cows[:switch2[0]] + list(reversed(cows[switch2[0]:switch2[1] + 1]))
        else:
            cows = cows[:switch2[0]] + list(reversed(cows[switch2[0]:switch2[1] + 1])) + cows[switch2[1] + 1:]


    for i in range(n):
            print(cows[i], file=out)
