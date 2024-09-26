"""
ID: lucaski2
LANG: PYTHON3
TASK: gift1
"""
inp = open("gift1.in", "r").readlines()
out = open("gift1.out", "w")
for i in range(len(inp)):
    inp[i] = inp[i].strip()

NP = int(inp[0])
inp.pop(0)

names = {inp[_]:0 for _ in range(NP)}
for i in range(NP):
    inp.pop(0)
for i in range(NP):
    person = inp[0]
    inp.pop(0)
    money, people = list(map(int, inp[0].split()))
    inp.pop(0)

    if people == 0:
        continue

    names[person] += (money % people) - money
    money -= money % people
    for j in range(people):
        names[inp[0]] += money / people
        inp.pop(0)

for ind, i in enumerate(names.items()):
    out.write(str(i[0]) + " " + str(int(i[1])) + "\n")

out.close()

