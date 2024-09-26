inp = open("traffic.in", "r")
out = open("traffic.out", "w")
N = int(inp.readline().strip())

actions = [inp.readline().strip().split() for _ in range(N)]

current_offset = [0, 0]
current_range = [None, None]
for act in actions:
    if act[0] == "on":
        current_offset[0] += int(act[1])
        current_offset[1] += int(act[2])
    elif act[0] == "off":
        current_offset[0] -= int(act[1])
        current_offset[1] -= int(act[2])
    
    else:
        if current_range == [None, None]:
            current_range = [int(act[1]) - current_offset[0], int(act[2]) - current_offset[1]]
        else:
            if current_range[0] < int(act[1]) - current_offset[0]:
                current_range[0] = int(act[1]) - current_offset[0]
            if current_range[1] > int(act[2]) - current_offset[1]:
                current_range[1] = int(act[2]) - current_offset[1]


print(current_range[0], current_range[1], file=out)

current_range = [None, None]
no_nones = True
for act in actions:
    act[1] = int(act[1])
    act[2] = int(act[2])
    if current_range == [None, None]:
        current_range = [int(act[1]), int(act[2])]
    elif act[0] == "on":
        current_range[0] += min(act[1], act[2])
        current_range[1] += max(act[1], act[2])
    
    elif act[0] == "off":
        current_range[0] -= max(act[1], act[2])
        current_range[1] -= min(act[1], act[2])
    else:
        if no_nones or current_range[0] < act[1]:
            current_range[0] = act[1]
        if no_nones or current_range[1] > act[2]:
            current_range[1] = act[2]
            no_nones = False

    print(current_range)
print(current_range[0], current_range[1], file=out)











