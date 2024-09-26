inp = input()
if inp[0] == "<" and inp[-1] == ">" and inp.count("=") == len(inp) - 2:
    print("Yes")
else:
    print("No")