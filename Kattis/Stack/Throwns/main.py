people, commands = list(map(int, input().split()))
inp = input().split(" ")
current_moves = []
undoables = []
last_undo = False

for i in range(len(inp)):

    if inp[i] == "undo":
        last_undo = True
    else:
        current_moves.append("u" + inp[i] if last_undo else inp[i])
        last_undo = False





# print(current_moves)


for i in range(commands):
    if current_moves[i][0] == "u":
        # print(i)
        for j in range(int(current_moves[i][1:])):
            undoables.pop()
            
    else:
        undoables.append(int(current_moves[i]))
        

print(sum(undoables) % people)