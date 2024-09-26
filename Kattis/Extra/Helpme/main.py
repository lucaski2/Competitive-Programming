inp = [input() for i in range(17)]
white = []
black = []
white_letters = "KQRBNP"
black_letters = "kqrbnp"
letters = "ABCDEFGH"


def sort_list(lst, black):
    #sort by first letter, but according to white_letters
    second_list = set()

    for i in range(len(lst)):
        for j in range(0, len(lst) - i - 1):
            if lst[j][0] not in white_letters:
                lst.append(lst[j])
                second_list.add(lst[j + 1])
                lst.pop(j)
                continue
            if lst[j + 1][0] not in white_letters:
                lst.append(lst[j + 1])
                second_list.add(lst[j + 1])
                lst.pop(j + 1)
                continue
            if list(white_letters).index(lst[j][0]) > list(white_letters).index(lst[j + 1][0]):
                # swap lst[j] and lst[j + 1]
                lst[j], lst[j + 1] = lst[j + 1], lst[j]

    second_list = list(second_list)
    if not black:
        second_list.sort(key=lambda x: x[1])
    else:
        second_list.sort(key=lambda x: x[1], reverse=True)
    return lst[:len(second_list)] + second_list

while '+---+---+---+---+---+---+---+---+' in inp:
    inp.remove('+---+---+---+---+---+---+---+---+')

for i in range(len(inp)):
    while ":" in inp[i]:
        inp[i] = inp[i].replace(":", "")
    while "." in inp[i]:
        inp[i] = inp[i].replace(".", "")

for y in range(len(inp)):
    current_x = -1
    for x in range(len(inp[y])):
        if inp[y][x] == "|":
            current_x += 1
        if inp[y][x] in white_letters:
            current_letter = inp[y][x] if inp[y][x].capitalize() != "P" else ""
            white.append(current_letter + str(letters[current_x].lower()) + str(8 - (y + 1) + 1))
        elif inp[y][x] in black_letters:
            current_letter = inp[y][x] if inp[y][x].capitalize() != "P" else ""
            black.append(current_letter.capitalize() + str(letters[current_x].lower()) + str(8 - (y + 1) + 1))

white = sort_list(white, False)
black = sort_list(black, True)
print("White: ", end="")
for i in range(len(white)):
    print(white[i] )

print("Black: ", end="")
for i in range(len(black)):
    if i + 1 == len(black):
        print(black[i])
    else:
        print(black[i], end=",")
