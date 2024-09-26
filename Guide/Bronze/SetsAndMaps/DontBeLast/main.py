import sys

inp = open("notlast.in", "r")
out = open("notlast.out", "w")

N = int(inp.readline().strip())

info = [inp.readline().strip().split() for _ in range(N)]
milk_produced = {"Bessie": 0, "Elsie": 0, "Daisy": 0, "Gertie": 0, "Annabelle": 0, "Maggie": 0, "Henrietta": 0}

for produced in info:
    milk_produced[produced[0]] += int(produced[1])

milk_produced = sorted(milk_produced.items(), key=lambda x: x[1])


cur_amount = milk_produced[0][1]
second_highest = -1

# for i, m in enumerate(milk_produced):
#     if m[1] == cur_amount:
#         continue

#     if second_highest == -1:
#         second_highest = m[1]
    
#     elif second_highest != -1 and m[1] != second_highest and i != 0:
#         print(milk_produced[i - 1][0], file=out)
#         sys.exit()


#     elif second_highest != -1 and m[1] == second_highest:
#         print("Tie", file=out)
#         sys.exit()

# print("Tie", file=out)

lowest = milk_produced[0][1]

if lowest == milk_produced[-1][1]:
    print("Tie", file=out)
    exit()

second_lowest = min([i[1] for i in milk_produced if i[1] != lowest])

cur_milk_produced = [i[1] for i in milk_produced]

if cur_milk_produced.count(second_lowest) > 1:
    print("Tie", file=out)
    exit()

print(min([i for i in milk_produced if i[1] != lowest], key=lambda x: x[1])[0], file=out)
