n = int(input())

rats = []
woman_and_child = []
men = []
captain = []
for i in range(n):
    name, status = input().split()
    if status == "rat":
        rats.append(name)
    elif status == "woman" or status == "child":
        woman_and_child.append(name)
    elif status == "man":
        men.append(name)
    elif status == "captain":
        captain.append(name)

if rats:
    print(*rats, sep="\n")
if woman_and_child:
    print(*woman_and_child, sep="\n")

if men:
    print(*men, sep="\n")
if captain:
    print(*captain, sep="\n")