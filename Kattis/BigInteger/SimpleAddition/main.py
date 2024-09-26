inp1 = input()
inp2 = input()

if len(inp1) < len(inp2):
    inp1 = "0" * (len(inp2) - len(inp1)) + inp1

elif len(inp1) > len(inp2):
    inp2 = "0" * (len(inp1) - len(inp2)) + inp2

# addition
ans = ""
rem = 0
for i in range(len(inp1) - 1, 0, -1):
    cur = str(int(inp1[i]) + int(inp2[i]) + rem)
    if int(cur) >= 10:
        rem = 1
        ans = cur[1] + ans
    else:
        rem = 0
        ans = cur + ans
    




print(str(int(inp1[0]) + int(inp2[0]) + rem) + ans)

