





def solve(house_num, house):
    print("House", house_num)
    house = list(map(list, house))
    # find asterisk index
    current_ind = None
    for i in range(len(house)):
        if "*" in house[i]:
            current_ind = (i, house[i].index("*"))

            if i == 0:
                direction = (1, 0)
            
            elif i == len(house) - 1:
                direction = (-1, 0)
            
            elif current_ind[1] == 0:
                direction = (0, 1)
            
            else:
                direction = (0, -1)
    
    
    while house[current_ind[0]][current_ind[1]] != "x":

        if house[current_ind[0]][current_ind[1]] == "/":
            direction = (0 if direction[0] else -direction[1], 0 if direction[1] else -direction[0])

        elif house[current_ind[0]][current_ind[1]] == "\\":
            direction = (0 if direction[0] else direction[1], 0 if direction[1] else direction[0])


        # move to next place
        current_ind = (current_ind[0] + direction[0], current_ind[1] + direction[1])
    
    house[current_ind[0]][current_ind[1]] = "&"

    # print house 

    for i in range(len(house)):
        print("".join(house[i]))





cur_num = 1
cur_input = input()

while cur_input != "0 0":

    current_house = [input() for _ in range(int(cur_input.split()[1]))]


    solve(cur_num, current_house)

    cur_num += 1

    cur_input = input()







