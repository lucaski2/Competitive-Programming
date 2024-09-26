inp = open("measurement.in", "r")
out = open("measurement.out", "w")
N = int(inp.readline().strip())

data = [inp.readline().strip().split() for _ in range(N)]
for i in range(N):
    data[i][0] = int(data[i][0])
    data[i][2] = int(data[i][2]) if data[i][2] != "+" else int(data[i][2][1:])

data.sort(key=lambda x: x[0])
current_counts = [7 for _ in range(3)]
count = 0
highest = 7
displayed = [True, True, True]
last_increment_day = -1
for i in range(N):
    if data[i][1] == "Mildred":
        current_counts[0] += data[i][2]
        cur_index = 0
    elif data[i][1] == "Elsie":
        current_counts[1] += data[i][2]
        cur_index = 1
    
    else:
        current_counts[2] += data[i][2]
        cur_index = 2

    for j in range(3):
        if current_counts[j] > highest:
            highest = current_counts[j]
    can_increment = True
    for j in range(3):
        if current_counts[j] == highest and not displayed[j] and data[i][0]:
            displayed[j] = True
            count += 1 if can_increment and data[i][0] != last_increment_day else 0
            can_increment = False
            last_increment_day = data[i][0]


        elif current_counts[j] < highest and displayed[j] and data[i][0]:
            displayed[j] = False
            count += 1 if can_increment and data[i][0] != last_increment_day else 0
            can_increment = False
            last_increment_day = data[i][0]

    

print(count, file=out)





