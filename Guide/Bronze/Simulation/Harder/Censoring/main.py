inp = open("censor.in", "r")
out = open("censor.out", "w")
st = inp.readline().strip()
substring = inp.readline().strip()
current_built_str = ""
length = len(substring)
for i in range(len(st)):
    current_built_str += st[i]
    if len(current_built_str) > len(substring) and current_built_str.endswith(substring):
        current_built_str = current_built_str[:-length]


print(current_built_str, file=out)



