N, P = list(map(int, input().split()))


fence_post_positions = []

cow_positions = []

for i in range(P):
    fence_post_positions.append(list(map(int, input().split())))

for j in range(P):
    cow_positions.append(list(map(int, input().split())))


# sort fence

# turn into dictionary
x_keys = {}
y_keys = {}

for i in fence_post_positions[1:]:
    if i[0] in x_keys:
        x_keys[i[0]].append(i[1])
    else:
        x_keys[i[0]] = [i[1]]

    if i[1] in y_keys:
        y_keys[i[1]].append(i[0])
    else:
        y_keys[i[1]] = [i[0]]

sorted_fences = [(0, 0)]
is_x = True
current_pos = (0, 0)
for i in range(P - 1):
    if is_x:
        sorted_fences.append((current_pos[0], x_keys[current_pos[0]][0]))
        x_keys[current_pos[0]].pop(0)
        current_pos = (sorted_fences[-1][1], sorted_fences[-1][1])
    else:
        sorted_fences.append((y_keys[current_pos[1]][0], current_pos[1]))
        y_keys[current_pos[1]].pop(0)
        current_pos = (sorted_fences[-1][0], sorted_fences[-1][0])
    is_x = not is_x

print(cow_positions)
for poses in cow_positions:
    
    # go back and forwards through sorted fences
    count = 0
    pos = (poses[0], poses[1])
    ind = sorted_fences.index(pos)
    targ = (poses[2], poses[3])
    while pos != targ:

        next_pos = sorted_fences[ind]
        if (next_pos[0] > targ[0] > pos[0] or pos[0] < targ[0] < next_pos[0]) and next_pos[1] == targ[1] == pos[1]:
            count += abs(pos[0] - targ[0])
            break
        if (next_pos[1] > targ[1] > pos[1] or pos[1] < targ[1] < next_pos[1]) and next_pos[0] == targ[0] == pos[0]:
            count += abs(pos[1] - targ[1])
            break
        ind += 1 if ind < len(sorted_fences) - 1 else -ind
        count += max(abs(pos[0] - next_pos[0]), abs(pos[1] - next_pos[1]))
        pos = next_pos

    print(count)


