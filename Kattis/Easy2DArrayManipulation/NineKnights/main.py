board = [list(input()) for _ in range(5)]

# go through each knight and see if it reaches any other knights

# check how many knights there are
count = 0
for i in range(5):
    for j in range(5):
        if board[i][j] == 'k':
            count += 1
if count != 9:
    print("invalid")
    exit()
for i in range(5):
    for j in range(5):
        if board[i][j] == 'k':
            # go through all possible moves of this knight
            possible_moves = [(i-1, j-2), (i-1, j+2), (i+1, j-2), (i+1, j+2), (i-2, j-1), (i-2, j+1), (i+2, j-1), (i+2, j+1)]
            for move in possible_moves:
                if 0 <= move[0] < 5 and 0 <= move[1] < 5:
                    if board[move[0]][move[1]] == 'k':
                        print("invalid")
                        exit()


print("valid")