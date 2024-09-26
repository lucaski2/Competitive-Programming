"""
ID: lucaski2
LANG: PYTHON3
TASK: beads
"""
inp = open("beads.in", "r")
out = open("beads.out", "w")
num_beads = int(inp.readline().strip())
beads = list(inp.readline().strip() * 2)

# go through break points
biggest_streak = 0
biggest_ind = -1
final_beads = ""
final_beads2 = ""
for i in range(len(beads)):
    # go both ways and see when u have to stop
    streak = 0
    starting_bead = "w"
    ind = i
    final = ""
    while beads[ind] == starting_bead or beads[ind] == "w" or starting_bead == "w":
        if streak > num_beads:
            break
        streak += 1

        if beads[ind] != "w":
            starting_bead = beads[ind]
        final += beads[ind]
        ind = (ind + 1) % len(beads)
        
    
    # go the other way
    starting_bead = ""
    final2 = ""
    ind = (i - 1) % len(beads)
    while beads[ind] == starting_bead or starting_bead == "" or beads[ind] == "w":
        if streak > num_beads:
            break
        streak += 1

        if beads[ind] != "w":
            starting_bead = beads[ind]
        final2 += beads[ind]
        ind = (ind - 1) % len(beads)
    if streak > biggest_streak:
        biggest_streak = streak
        biggest_ind = i
        final_beads = final
        final_beads2 = final2

# print(final_beads, final_beads2)
# print(biggest_ind, biggest_streak)
if biggest_streak > num_beads:
    biggest_streak = num_beads
print(biggest_streak, file=out)



