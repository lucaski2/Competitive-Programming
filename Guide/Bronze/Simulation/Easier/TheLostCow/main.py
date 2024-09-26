inp = open("lostcow.in", "r")
out = open("lostcow.out", "w")

farmer, cow = list(map(int, inp.readline().split()))
count = 0
current_pos = farmer
cur_move = 1
last_pos = farmer
while True:
    # print(cur_move)
    for i in range(abs(current_pos - farmer) + abs(cur_move)):
        # print(current_pos)
        if current_pos == cow:
            out.write(str(count))
            exit()
        current_pos += -1 if cur_move < 0 else 1
        # print(-1 if cur_move < 0 else 1)
        count += 1
    cur_move *= -2
    print(cur_move)
