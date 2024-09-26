board = [list(map(int, input().split())) for _ in range(4)]
movement = int(input())

if movement == 0:
    for i in range(4):
        last_num = board[i][0]
        last_ind = 0
        for j in range(1, 4):
            if last_num == board[i][j]:
                # combine last index and current index into last index and then shift all items to the left
                board[i][last_ind] = last_num * 2
                board[i][j] = 0
                last_ind += 1
                last_num = 0

            elif board[i][j] != 0:
                last_num = board[i][j]
                last_ind = j

    # go through and push all values to the left
    current_ind = 0
    for row in board:
        current_ind = 0
        row_copy = row.copy()
        print(row)
        for num in row_copy:
            if num != 0:
                row[current_ind] = num
                current_ind += 1
        
        print(row)

if movement == 2:
    for i in range(4):
        last_num = board[i][3]
        last_ind = 3
        for j in range(2, -1, -1):
            if last_num == board[i][j]:
                board[i][last_ind] = last_num * 2
                board[i][j] = 0
                last_ind -= 1
                last_num = 0

            elif board[i][j] != 0:
                last_num = board[i][j]
                last_ind = j

    # go through and push all values to the right
    
    for i in range(4):
        # repeat until fully pushed to the right
        while board[i][:board[i].count(0)] != [0 for _ in range(board[i].count(0))]:
            for j in range(3, 0, -1):
                if board[i][j] == 0:
                    board[i][j] = board[i][j - 1]
                    board[i][j - 1] = 0

# do the same as previous two if statements but do everything up instead of left or right
                
if movement == 1:
    for i in range(4):
        last_num = board[0][i]
        last_ind = 0
        for j in range(1, 4):
            if last_num == board[j][i]:
                board[last_ind][i] = last_num * 2
                board[j][i] = 0
                last_ind += 1
                last_num = 0

            elif board[j][i] != 0:
                last_num = board[j][i]
                last_ind = j

    # go through and push values up
    
    for i in range(3):
        for j in range(4):
            if board[i][j] == 0:
                board[i][j] = board[i + 1][j]
                board[i + 1][j] = 0
    

if movement == 3:
    for i in range(4):
        last_num = board[3][i]
        last_ind = 3
        for j in range(2, -1, -1):
            if last_num == board[j][i]:
                board[last_ind][i] = last_num * 2
                board[j][i] = 0
                last_ind -= 1
                last_num = 0

            elif board[j][i] != 0:
                last_num = board[j][i]
                last_ind = j
    
    # go through and push values down
    
    for i in range(3, 0, -1):
        for j in range(4):
            if board[i][j] == 0:
                board[i][j] = board[i - 1][j]
                board[i - 1][j] = 0

for i in range(4):
    print(*board[i])